#include "benchmark.h"
#include "PQ.h"

void ensure_parent_directory(const std::string& filename)
{
    std::filesystem::create_directories(std::filesystem::path(filename).parent_path());
}

double measure(PQ* pq, std::function<void(PQ*)> op, int inner_reps)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < inner_reps; i++)
    {
        op(pq);
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double>(end - start).count() / inner_reps;
}

double run_copies(int n, PQ* pq, std::function<void(PQ*)> op, int priority_max, int inner_reps, int series_seed)
{
    const int COPIES = 10;
    int value, priority;

    std::mt19937 gen(series_seed);

    std::uniform_int_distribution<int> dist_value(-100000, 100000);
    std::uniform_int_distribution<int> dist_priority(0, priority_max);

    for (int i = 0; i < n; i++)
    {
        value = dist_value(gen);
        priority = dist_priority(gen);

        pq->insert(value, priority);
    }

    //copies 
    std::vector<PQ*> copies;

    for (int i = 0; i < COPIES; i++)
    {
        copies.push_back(pq->clone());
    }

    double sum = 0.0;

    for (int i = 0; i < COPIES; i++)
    {
        sum += measure(copies[i], op, inner_reps);
    }

    //free memory
    for (auto p : copies)
    {
        delete p;
    }

    return sum / COPIES;
}

double run_series(int n, PQ* pq, std::function<void(PQ*)> op, int priority_max, int inner_reps, int base_seed)
{
    double sum = 0.0;
    const int REPS = 10;
    int series_seed;

    for (int i = 0; i < REPS; i++)
    {
        series_seed = base_seed + i;
        sum += run_copies(n, pq, op, priority_max, inner_reps, series_seed);
    }

    return sum / REPS;
}

double run_benchmark(const std::string& filename, PQ* pq, std::function<void(PQ*)> op, int inner_reps = 1, int base_seed = 12345)
{
    int TIMES_PRIORITY = 3;
    ensure_parent_directory(filename);

    std::ofstream file(filename);

    file << std::fixed;
    file.precision(10);

    file << "N,time\n";

    for (int n = 5000; n <= 80000; n += 5000)
    {
        double result = run_series(n, pq, op, n * TIMES_PRIORITY, inner_reps, base_seed);

        file << n << "," << result << "\n";

        std::cout << filename << "n=" << n << std::endl;
    }

    file.close();
}

void benchmark_insert() 
{
    std::string result_path = "results/insert/"
}