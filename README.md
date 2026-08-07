<div align="center">

# Data Structures & Benchmarks

**C++ data structure implementations, each paired with a benchmark harness that checks whether the textbook complexity actually holds up.**

[![Build](https://github.com/NikonAndr/data-structures/actions/workflows/build.yml/badge.svg)](https://github.com/NikonAndr/data-structures/actions/workflows/build.yml)
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/benchmarks-Python%203-3776AB?logo=python&logoColor=white)

</div>

Three independent data structure projects, built from scratch in C++ with no STL containers and no external C++ dependencies. Each one is measured, not just implemented: a Python benchmark pipeline times every core operation across a range of input sizes and turns the results into comparison plots.

## Projects

### [`hash-map/`](./hash-map) — three collision strategies compared

Same `insert`/`remove` interface, three different ways of resolving collisions: separate chaining with a linked list (`HashMapList`), separate chaining with an AVL tree per bucket (`HashMapAVL`), and open addressing with linear probing and tombstone deletion (`HashMapLinear`).

### [`heap-array/`](./heap-array) — priority queue, array vs. binary heap

An unsorted dynamic array (`ArrayPQ`) against a binary heap (`HeapPQ`) as the backing structure for a priority queue — benchmarks `insert`, `extract_max`, `peek`, and `modify_key`, the operations where the two approaches trade places on which is faster.

### [`linear_structures_benchmark/`](./linear_structures_benchmark) — array vs. singly/doubly linked list

A dynamic array against singly- and doubly-linked lists on `push_back`, `push_front`, `pop_back`, `pop_front`, `insert`, `remove`, and `find`.

## Common pattern

Every subproject follows the same workflow:

1. A C++ program generates random data, runs timed operations over multiple seeds, and writes results to CSV under `results/`
2. `visualisation/charts.py` (Python, pandas + matplotlib) reads the CSVs and produces comparison plots under `visualisation/plots/`

See each subfolder's own README for the specific operations benchmarked and how to build it.

## Tech Stack

* C++17, no external C++ dependencies
* Python 3 (pandas, matplotlib) for result visualisation
* GitHub Actions — compiles all three projects on every push
