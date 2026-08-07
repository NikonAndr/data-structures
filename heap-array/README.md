# Priority Queue — Array vs. Binary Heap

**Two C++ priority queue implementations, benchmarked against each other across every core operation.**

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/benchmarks-Python%203-3776AB?logo=python&logoColor=white)

## About

Both `ArrayPQ` and `HeapPQ` implement the same abstract `PQ` interface (`insert`, `extract_max`, `peek`, `modify_key`), so the only thing that changes between them is which operations are fast:

* **`ArrayPQ`** — an unsorted dynamic array. `insert` is O(1) amortized (just append), but `extract_max` and `peek` have to scan the whole array for the maximum: O(n).
* **`HeapPQ`** — a binary heap over a dynamic array, maintained with `heapify_up`/`heapify_down`. `insert` and `extract_max` are O(log n), and `peek` is O(1) since the max always sits at the root.

Benchmarking both side by side makes the classic "cheap insert vs. cheap extract" trade-off concrete instead of theoretical.

## Architecture

```
main.cpp
  └── Interface        // menu: HeapPQ / ArrayPQ / Benchmark
        └── PQ (abstract)
              ├── ArrayPQ   // unsorted dynamic array
              └── HeapPQ    // binary heap (heapify_up / heapify_down)
```

## Usage

### Build & run

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/program
./build/program
```

Menu: `HeapPQ` / `ArrayPQ` / `Benchmark` / `exit` — the first two let you `insert`, `extract_max`, `peek`, and `modify_key` interactively; `Benchmark` runs the full timed comparison.

### Benchmark

`run_all_benchmarks()` times `insert`, `extract_max`, `peek`, and `modify_key` for both structures across a range of sizes, writing CSVs to `results/<operation>/<Structure>.csv`.

### Charts

```bash
python visualisation/charts.py
```

Reads the CSVs and writes comparison plots to `visualisation/plots/`. For `extract_max` and `peek`, it additionally plots the heap on its own scale (`*_heap_only.png`) — useful since the heap is often so much faster that it's invisible on a shared axis with the array.

## Benchmarked operations

| Operation | ArrayPQ | HeapPQ |
|---|---|---|
| `insert` | O(1) amortized | O(log n) |
| `extract_max` | O(n) | O(log n) |
| `peek` | O(n) | O(1) |
| `modify_key` | O(n) | O(n) |

## Current limitations

* `modify_key` is O(n) on both structures — `HeapPQ` doesn't maintain a value-to-index map, so it has to search before it can re-heapify
* Priority and value are fixed as `int`

## Tech Stack

* C++17
* Python 3 (pandas, matplotlib) for benchmarking output