#pragma once 

#include <string>
#include <filesystem>
#include <fstream>
#include <random>
#include <chrono>
#include <exception>
#include <iostream>

enum class OpType
{
    INSERT,
    REMOVE
};

template <typename MapType>
double run_batch(MapType& map, int* keys, int batch_size, OpType operation)
{
    if (operation == OpType::INSERT)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < batch_size; i++)
        {
            map.insert(keys[i], 123);
        }
        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration<double>(end - start).count() / batch_size;
    }
    else if (operation == OpType::REMOVE)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < batch_size; i++)
        {
            map.remove(keys[i]);
        }
        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration<double>(end - start).count() / batch_size;
    }
    else
    {
        throw std::runtime_error("[BENCHMARK] run_batch: wrong OpType");
    }
    
}

template <typename MapType> 
double run_seed(int n, OpType operation, int seed)
{
    MapType map;
    int batch_size = n * 0.05;

    std::mt19937 gen(seed);

    std::uniform_int_distribution<int> dist_key(-1'000'000, 1'000'000);
    std::uniform_int_distribution<int> dist_value(0, 1'000'000);

    int* build_keys = new int[n];
    for (int i = 0; i < n; i++)
    {
        int key = dist_key(gen);
        int value = dist_value(gen);
        map.insert(key, value);
        build_keys[i] = key;
    }

    int* batch_keys = new int[batch_size];
    if (operation == OpType::INSERT)
    {
        for (int i = 0; i < batch_size; i++)
        {
            batch_keys[i] = dist_key(gen);
        }
    }
    else if (operation == OpType::REMOVE)
    {
        std::shuffle(build_keys, build_keys + n, gen);
        for (int i = 0; i < batch_size; i++)
        {
            batch_keys[i] = build_keys[i];
        }
    }

    double result = run_batch<MapType>(map, batch_keys, batch_size, operation);

    delete[] build_keys;
    delete[] batch_keys;
    return result;
}

template <typename MapType>
double run_seeds(int n, OpType operation, int base_seed)
{
    const int SEED_NUMBER = 30;
    double result = 0.0;

    for (int i = 0; i < SEED_NUMBER; i++)
    {
        result += run_seed<MapType>(n, operation, base_seed + i);
    }

    return result / SEED_NUMBER;
}

//helper function to ensure that parent directory exists 
inline void ensure_parent_directory(const std::string& filename)
{
    std::filesystem::create_directories(std::filesystem::path(filename).parent_path());
}

template <typename MapType>
void run_benchmark(const std::string& filename, OpType operation, int base_seed = 12345)
{
    ensure_parent_directory(filename);

    std::ofstream file(filename);

    file << std::fixed;
    file.precision(10);

    file << "N,time\n";

    for (int n = 10000; n <= 80000; n += 5000)
    {
        double result = run_seeds<MapType>(n, operation, base_seed);

        file << n << "," << result << "\n";

        std::cout << filename << " n= " << n << std::endl;
    }

    file.close();
}

void run_all_benchmarks();