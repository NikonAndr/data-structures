#pragma once
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include <filesystem>

//measures time of a single operation, for quick operation's measures based on inner_reps 
template <typename Structure, typename Operation>
double measure(Operation op, Structure& list, int inner_reps, bool is_find, int find_value)
{
    auto start = std::chrono::high_resolution_clock::now();

    //check for find exception
    if (is_find)
    {
        for (int i = 0; i < inner_reps; i++)
        {
            volatile int result = list.find(find_value);
        }
    }
    else 
    {
        for (int i = 0; i < inner_reps; i++)
        {
            op(list);
        }  
    }
    
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double>(end - start).count() / inner_reps;
}

//run_copies
template <typename Structure, typename Operation>
double run_copies(int n, Operation op, int inner_reps, bool is_find, int series_seed)
{
    const int LIST_COPIES = 10;
    Structure list;

    int random_value;
    int find_value = 0;

    //initialize random
    std::mt19937 gen(series_seed);

    std::uniform_int_distribution<int> dist(-100000, 100000);

    //fill list 
    for (int i = 0; i < n; i++)
    {
        random_value = dist(gen);

        list.push_back(random_value);

        //set a find_val if is_find
        if (is_find && i == n/2)
        {
            find_value = random_value;
        }
    }

    //make copies of the list
    std::vector<Structure> lists(LIST_COPIES, list);

    double sum = 0.0;

    for (int i = 0; i < LIST_COPIES; i++)
    {
        sum += measure<Structure>(op, lists[i], inner_reps, is_find, find_value);
    }

    return sum / LIST_COPIES;
    
}

//runs series of measurements with different seeds 
template <typename Structure, typename Operation>
double run_series(int n, Operation op, int inner_reps, bool is_find, int base_seed)
{
    double sum = 0.0;
    const int REPS = 10;
    int series_seed;

    for (int i = 0; i < REPS; i++)
    {
        series_seed = base_seed + i;
        sum += run_copies<Structure>(n, op, inner_reps, is_find, series_seed);
    }

    return sum / REPS;
}

//helper function to ensure that parent directory exists 
inline void ensure_parent_directory(const std::string& filename)
{
    std::filesystem::create_directories(std::filesystem::path(filename).parent_path());
}

//runs complete benchmark on the structure with given method
template <typename Structure, typename Operation>
void run_benchmark(const std::string& filename, Operation op, int inner_reps = 1, bool is_find = false, int seed = 12345)
{
    ensure_parent_directory(filename);

    std::ofstream file(filename);

    file << std::fixed;
    file.precision(10);

    file << "N,time\n";

    for (int n = 5000; n <= 80000; n += 5000)
    {
        double result = run_series<Structure>(n, op, inner_reps, is_find, seed);

        file << n << "," << result << "\n";

        std::cout << filename << " n=" << n << std::endl;
    }

    file.close();
}

//declarations
void benchmark_push_back();
void benchmark_push_front();
void benchmark_pop_back();
void benchmark_pop_front();
void benchmark_insert();
void benchmark_remove();
void benchmark_find();
void run_all_benchmarks();
