#pragma once

#include "ArrayPQ.h"
#include "HeapPQ.h"
#include "benchmark.h"
#include "PQ.h"

class Interface
{
private:
    PQ* pq;
public:
    ~Interface();
    void main_if();
    void benchmark_if();
    void array_if();
    void heap_if();
};