#include "benchmark.h"

#include "HashMapAVL.h"
#include "HashMapLinear.h"
#include "HashMapList.h"

void run_all_benchmarks()
{
    std::string output_path = "results/insert/";

    run_benchmark<HashMapAVL>(output_path + "AVL.csv", OpType::INSERT);
    run_benchmark<HashMapLinear>(output_path + "Linear.csv", OpType::INSERT);
    run_benchmark<HashMapList>(output_path + "List.csv", OpType::INSERT);

    output_path = "results/remove/";

    run_benchmark<HashMapAVL>(output_path + "AVL.csv", OpType::REMOVE);
    run_benchmark<HashMapLinear>(output_path + "Linear.csv", OpType::REMOVE);
    run_benchmark<HashMapList>(output_path + "List.csv", OpType::REMOVE);
}