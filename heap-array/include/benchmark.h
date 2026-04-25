#pragma once 

#include "PQ.h"

#include <chrono>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <filesystem>
#include <functional>

void ensure_parent_directory(const std::string& filename);

double measure(PQ* pq, std::function<void(PQ*, const std::vector<int>&)> op, const std::vector<int>& values, int inner_reps = 1);

double run_copies(int n, std::function<PQ*()> create, std::function<void(PQ*, const std::vector<int>&)> op, int priority_max, int inner_reps = 1, int series_seed = 12345);

double run_series(int n, std::function<PQ*()> create, std::function<void(PQ*, const std::vector<int>&)> op, int priority_max, int inner_reps = 1, int base_seed = 12345);

double run_benchmark(const std::string& filename, std::function<PQ*()> create, std::function<void(PQ*, const std::vector<int>&)> op, int inner_reps = 1, int base_seed = 12345);

void benchmark_insert();
void benchmark_extract_max();
void benchmark_peek();
void benchmark_modify_key();
void run_all_benchmarks();
