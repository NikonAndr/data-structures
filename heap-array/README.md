# 📊 Priority Queue Benchmark

## 🔍 Overview

Projekt porównuje wydajność dwóch implementacji kolejki priorytetowej w C++:

* Nieposortowana tablica dynamiczna (ArrayPQ)
* Kopiec binarny (HeapPQ)

Dla każdej struktury mierzony jest czas wykonania operacji i zapisywany do plików CSV, a następnie wizualizowany w Pythonie.

---

## 📁 Project Structure

```text
include/            # nagłówki C++
src/                # implementacje i benchmark
results/            # wyniki (CSV)
visualisation/      # skrypt do wykresów
  └── charts.py
README.md
```

---

## ⚙️ Requirements

### 🔧 C++

* Kompilator C++ (g++, clang lub MSVC)
* Standard: C++17

### 🐍 Python

* Python 3.x

Biblioteki:

```bash
pip install pandas matplotlib
```

---

## 🚀 How to Run

### 1. Kompilacja

#### 🐧 Linux / macOS

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/program
```

#### 🪟 Windows

##### Opcja 1: MinGW (g++)

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/program.exe
```

##### Opcja 2: Visual Studio (MSVC)

```bash
cl /std:c++17 /Iinclude src\*.cpp /Fe:build\program.exe
```

---

### 2. Uruchom benchmark

```bash
./build/program
```

Windows:

```bash
build\program.exe
```

👉 Program zapyta czy wyczyścić poprzednie wyniki, a następnie wygeneruje dane w folderze `results/`

---

### 3. Wygeneruj wykresy

```bash
python visualisation/charts.py
```

Jeśli nie działa:

```bash
python3 visualisation/charts.py
```

---

## 📊 Results

### 📁 Dane (CSV)

```text
results/[operation]/[structure].csv
```

np:

```text
results/insert/ArrayPQ.csv
results/extract_max/HeapPQ.csv
```

---

### 📈 Wykresy

Zapisywane automatycznie w:

```text
visualisation/plots/
```

np:

```text
insert.png
extract_max.png
extract_max_heap_only.png
peek.png
peek_heap_only.png
modify.png
```

> Wykresy `*_heap_only.png` pokazują zachowanie samego kopca w osobnej skali — przydatne dla operacji gdzie Heap jest tak szybki, że na wspólnym wykresie z Array jest niewidoczny.

---

## 🧪 Benchmarked Operations

| Operacja | ArrayPQ | HeapPQ |
|---|---|---|
| `insert` | O(1) amort. | O(log n) |
| `extract_max` | O(n) | O(log n) |
| `peek` | O(n) | O(1) |
| `modify_key` | O(n) | O(n) |

---

## 🧠 How it works

1. Program C++:

   * generuje losowe dane
   * wypełnia struktury i wykonuje operacje
   * mierzy czas za pomocą `std::chrono`
   * uśrednia wyniki z wielu serii i kopii
   * zapisuje wyniki do CSV

2. Python:

   * wczytuje CSV
   * generuje wykresy porównawcze
   * dla `extract_max` i `peek` generuje też osobny wykres dla Heap
   * zapisuje wszystko jako PNG

---

## ⚠️ Notes

* Najpierw uruchom benchmark (C++)
* Dopiero potem generuj wykresy (Python)
* Jeśli folder `results/` jest pusty → brak wykresów

---

## 💡 Tip

Jeśli wykresy się nie pojawiają, upewnij się że:

* benchmark został uruchomiony
* pliki `.csv` istnieją w `results/`
* masz zainstalowane biblioteki Python (`pandas`, `matplotlib`)