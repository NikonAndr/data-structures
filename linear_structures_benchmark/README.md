# Linear Structures Benchmark — Array vs. Singly/Doubly Linked List

**Three C++ list implementations, benchmarked to make the classic array-vs-list trade-offs concrete instead of theoretical.**

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B&logoColor=white)
![Python](https://img.shields.io/badge/benchmarks-Python%203-3776AB?logo=python&logoColor=white)

## About

`ArrayList`, `SinglyList`, and `DoublyList` all expose the same operations — `push_back`, `push_front`, `pop_back`, `pop_front`, `insert`, `remove`, `find` — as independent, hand-rolled implementations (no shared base class, no STL). The point is watching where contiguous storage wins (cache-friendly access, `find`) and where it loses (`push_front`/`pop_front`, which force a full shift on the array but are O(1) on the lists).

## Architecture

```
main.cpp
  └── Interface        // menu: ArrayList / SinglyList / DoublyList / Benchmark
        ├── ArrayList     // contiguous dynamic array
        ├── SinglyList    // singly linked list
        └── DoublyList    // doubly linked list
```

## Usage

### Build & run

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/program
./build/program
```

Menu: `ArrayList` / `SinglyList` / `DoublyList` / `Benchmark` / `exit` — the first three let you `push_back`, `push_front`, `pop_back`, `pop_front`, `insert`, `remove`, and `find` interactively; `Benchmark` runs the full timed comparison.

### Benchmark

Times `push_back`, `push_front`, `pop_back`, `pop_front`, `insert`, `remove`, and `find` for all three structures, `n` from 5,000 to 80,000 in steps of 5,000, averaged over 10 seeds × 10 copies per seed (`run_benchmark` → `run_series` → `run_copies` in `benchmark.h`). Writes CSVs to `results/<operation>/<structure>.csv`.

### Charts

```bash
python visualisation/charts.py
```

Reads the CSVs and writes comparison plots to `visualisation/plots/`. `push_front`, `pop_back`, and `pop_front` are plotted on a log scale, since the gap between O(1) list operations and O(n) array shifting gets large enough to flatten a linear plot.

## Current limitations

* Elements are fixed as `int` — no templating over element type
* No iterator support; traversal only happens internally (`find`, `print`)

## Tech Stack

* C++17
* Python 3 (pandas, matplotlib) for benchmarking output

## 💡 Tip

Jeśli wykresy się nie pojawiają, upewnij się że:

* benchmark został uruchomiony
* pliki `.csv` istnieją w `results/`

---
