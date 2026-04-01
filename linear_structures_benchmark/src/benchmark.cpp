#include "benchmark.h"
#include <array_list.h>
#include <singly_list.h>
#include "doubly_list.h"

#include <fstream>
#include <iostream>
#include <string>

void benchmark_push_back()
{
    std::string result_path = "results/push_back/";

    auto op = [](auto& list) {
        list.push_back(123);
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op, 5000);
    run_benchmark<SinglyList>(result_path + "singly.csv", op, 5000);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op, 5000);
}

void benchmark_push_front()
{
    std::string result_path = "results/push_front/";

    auto op = [](auto& list) {
        list.push_front(123);
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op);
    run_benchmark<SinglyList>(result_path + "singly.csv", op, 5000);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op, 5000);
}

void benchmark_pop_back()
{
    std::string result_path = "results/pop_back/";

    auto op = [](auto& list) {
        list.pop_back();
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op, 5000);
    run_benchmark<SinglyList>(result_path + "singly.csv", op);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op, 5000);
}

void benchmark_pop_front()
{
    std::string result_path = "results/pop_front/";

    auto op = [](auto& list) {
        list.pop_front();
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op);
    run_benchmark<SinglyList>(result_path + "singly.csv", op, 5000);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op, 5000);
}

void benchmark_insert()
{
    std::string result_path = "results/insert/";

    //insert at the middle of the list
    auto op = [](auto& list) {
        list.insert(123, list.size_of() / 2);
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op);
    run_benchmark<SinglyList>(result_path + "singly.csv", op);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op);
}

void benchmark_remove()
{
    std::string result_path = "results/remove/";

    //remove at the middle of the list 
    auto op = [](auto& list) {
        list.remove(list.size_of() / 2);
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op);
    run_benchmark<SinglyList>(result_path + "singly.csv", op);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op);
}

void benchmark_find()
{
    std::string result_path = "results/find/";

    //find a value (for the benchmark purpouse argument value does not matter)
    //benchmark automaticly detects value in the middle of the list, passes it to find
    auto op = [](auto& list) {
        list.find(123);
    };

    run_benchmark<ArrayList>(result_path + "array.csv", op, true);
    run_benchmark<SinglyList>(result_path + "singly.csv", op, true);
    run_benchmark<DoublyList>(result_path + "doubly.csv", op, true);
}
void run_all_benchmarks()
{
    benchmark_push_back();
    benchmark_push_front();
    benchmark_pop_back();
    benchmark_pop_front();
    benchmark_insert();
    benchmark_remove();
    benchmark_find();
}