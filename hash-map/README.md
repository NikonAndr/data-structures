# Hash Map — Collision Strategy Benchmark

**Three C++ hash map implementations, benchmarked head-to-head on how they resolve collisions.**

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/benchmarks-Python%203-3776AB?logo=python&logoColor=white)

## About

Same `insert(key, value)` / `remove(key)` contract, three different answers to "what happens when two keys hash to the same slot":

* **`HashMapList`** — separate chaining, each bucket is a singly linked list (`LinkedList`)
* **`HashMapAVL`** — separate chaining, each bucket is a self-balancing AVL tree, keeping worst-case per-bucket lookup at O(log n) instead of the O(n) a linked-list bucket degrades to once a bucket gets hash-flooded
* **`HashMapLinear`** — open addressing with linear probing: no buckets at all, just one flat array (`Entry*`) with tombstone-marked deletions (`Entry.deleted`) and automatic resizing when it gets too full

The point of building all three side by side is watching that AVL-bucket trade-off actually pay off under adversarial key distributions, instead of just taking the textbook claim on faith.

## Architecture

```
main.cpp
  └── Interface        // menu: AVL / Linear / List / Benchmarks
        ├── HashMapAVL      // separate chaining, AVL-tree buckets
        ├── HashMapLinear   // open addressing, linear probing, tombstones
        └── HashMapList     // separate chaining, linked-list buckets
              └── LinkedList / AVL   // per-bucket storage
```

## Usage

### Build & run

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/program
./build/program
```

Menu: `AVL` / `Linear` / `List` / `Benchmarks` / `exit` — the first three let you `insert`/`remove`/`print` interactively; `Benchmarks` runs the full timed comparison.

### Benchmark

`run_all_benchmarks()` times `insert` and `remove` for all three map types, for `n` from 10,000 to 80,000 in steps of 5,000, averaged over 30 random seeds per data point (`run_benchmark` → `run_seeds` → `run_seed` in `benchmark.h`). Results land in `results/insert/<Type>.csv` and `results/remove/<Type>.csv`.

### Charts and tables

```bash
python visualisation/charts.py
```

Reads the CSVs and writes comparison plots to `visualisation/plots/`, plus LaTeX-formatted result tables to `visualisation/tables/`.

## Current limitations

* Keys and values are fixed as `int` — no templating over key/value type
* `HashMapAVL`'s per-bucket tree isn't rebalanced across buckets, only within one — an unlucky hash function could still concentrate load on a few buckets

## Tech Stack

* C++17
* Python 3 (pandas, matplotlib) for benchmarking output
