#include "benchmark.h"
#include "PQ.h"
#include "ArrayPQ.h"
#include "HeapPQ.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

void ensure_parent_directory(const std::string& filename)
{
    std::filesystem::create_directories(std::filesystem::path(filename).parent_path());
}

double measure(PQ* pq, std::function<void(PQ*, const std::vector<int>&)> op, const std::vector<int>& values, int inner_reps)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < inner_reps; i++)
    {
        op(pq, values);
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double>(end - start).count() / inner_reps;
}

double run_copies(int n, std::function<PQ*()> create, std::function<void(PQ*, const std::vector<int>&)> op, int priority_max, int inner_reps, int series_seed)
{
    const int COPIES = 10;

    std::mt19937 gen(series_seed);
    std::uniform_int_distribution<int> dist_value(-100000, 100000);
    std::uniform_int_distribution<int> dist_priority(0, priority_max);

    double sum = 0.0;

    for (int i = 0; i < COPIES; i++)
    {
        //values for modify-key benchmark
        std::vector<int> values;
        PQ* pq = create();

        for (int j = 0; j < n; j++)
        {
            int value = dist_value(gen);
            int priority = dist_priority(gen);

            pq->insert(value, priority);
            values.push_back(value);
        }

        sum += measure(pq, op, values, inner_reps);

        delete pq;
    }

    return sum / COPIES;
}

double run_series(int n, std::function<PQ*()> create, std::function<void(PQ*, const std::vector<int>&)> op, int priority_max, int inner_reps, int base_seed)
{
    double sum = 0.0;
    const int REPS = 10;
    int series_seed;

    for (int i = 0; i < REPS; i++)
    {
        series_seed = base_seed + i;
        sum += run_copies(n, create, op, priority_max, inner_reps, series_seed);
    }

    return sum / REPS;
}

double run_benchmark(const std::string& filename, std::function<PQ*()> create, std::function<void(PQ*, const std::vector<int>&)> op, int inner_reps, int base_seed)
{
    int TIMES_PRIORITY = 3;
    ensure_parent_directory(filename);

    std::ofstream file(filename);

    file << std::fixed;
    file.precision(10);

    file << "N,time\n";
 
    double result = 0.0;

    for (int n = 5000; n <= 80000; n += 5000)
    {
        result = run_series(n, create, op, n * TIMES_PRIORITY, inner_reps, base_seed);

        file << n << "," << result << "\n";

        std::cout << filename << "n=" << n << std::endl;
    }

    file.close();

    return result;
}

void benchmark_insert(std::function<PQ*()> create, int base_seed) 
{
    PQ* temp = create();
    std::string result_path = "results/insert/" + temp->name() + ".csv";
    delete temp;

    int inner_reps = 100;

    run_benchmark(
        result_path,
        create,
        [](PQ* pq, const std::vector<int>&)
        {
            //generate random values 
            static std::mt19937 gen(123);
            static std::uniform_int_distribution<int> dist_value(-100000, 100000);
            static std::uniform_int_distribution<int> dist_priority(0, 100000);

            pq->insert(dist_value(gen), dist_priority(gen));
        },
        inner_reps,
        base_seed
    );
}

void benchmark_extract_max(std::function<PQ*()> create, int base_seed)
{
    PQ* temp = create();
    std::string result_path = "results/extract_max/" + temp->name() + ".csv";
    delete temp;
    
    int inner_reps = 50;

    run_benchmark(
        result_path,
        create,
        [](PQ* pq, const std::vector<int>&)
        {
            pq->extract_max();
        },
        inner_reps,
        base_seed
    );
}

void benchmark_peek(std::function<PQ*()> create, int base_seed)
{
    PQ* temp = create();
    std::string result_path = "results/peek/" + temp->name() + ".csv";
    delete temp;
    
    int inner_reps = 100;

    run_benchmark(
        result_path,
        create,
        [](PQ* pq, const std::vector<int>&)
        {
            pq->peek();
        },
        inner_reps,
        base_seed
    );
}

void benchmark_modify_key(std::function<PQ*()> create, int base_seed)
{
    PQ* temp = create();
    std::string result_path = "results/modify_key/" + temp->name() + ".csv";
    delete temp;
    
    int inner_reps = 100;

    run_benchmark(
        result_path,
        create,
        [](PQ* pq, const std::vector<int>& values)
        {
            static std::mt19937 gen(123);
            std::uniform_int_distribution<int> idx_dist(0, values.size() - 1);
            static std::uniform_int_distribution<int> prio_dist(0, 100000);

            if (values.empty()) return;
            
            int value = values[idx_dist(gen)];

            pq->modify_key(value, prio_dist(gen));
        },
        inner_reps,
        base_seed
    );
}

void run_all_benchmarks()
{
    auto create_array = []() { return new ArrayPQ(); };
    auto create_heap = []() { return new HeapPQ(); };
    int base_seed = 12345;

    //benchmarks for array_pq
    benchmark_insert(create_array, base_seed);
    benchmark_extract_max(create_array, base_seed);
    benchmark_peek(create_array, base_seed);
    benchmark_modify_key(create_array, base_seed);

    //benchmarks for heap_pq
    benchmark_insert(create_heap, base_seed);
    benchmark_extract_max(create_heap, base_seed);
    benchmark_peek(create_heap, base_seed);
    benchmark_modify_key(create_heap, base_seed);
}

