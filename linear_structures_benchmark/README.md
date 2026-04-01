# 📊 Linear Structures Benchmark

## 🔍 Overview

Projekt porównuje wydajność podstawowych struktur danych zaimplementowanych w C++:

* Dynamiczna tablica (ArrayList)
* Lista jednokierunkowa (Singly Linked List)
* Lista dwukierunkowa (Doubly Linked List)

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

# 🐧 Linux / macOS

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o program ./program
```

# 🪟 Windows

## Opcja 1: MinGW (g++)

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o program.exe program.exe
```

## Opcja 2: Visual Studio (MSVC)

```bash
cl /std:c++17 /Iinclude src\*.cpp program.exe
```

---

### 2. Uruchom benchmark

```bash
./program
```

Windows:

```bash
program.exe
```

👉 Program wygeneruje dane w folderze `results/`

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
results/push_back/array.csv
```

---

### 📈 Wykresy

Zapisywane automatycznie w:

```text
visualisation/plots/
```

np:

```text
push_back.png
find.png
```

---

## 🧠 How it works

1. Program C++:

   * generuje dane
   * wykonuje operacje na strukturach
   * mierzy czas
   * zapisuje wyniki do CSV

2. Python:

   * wczytuje CSV
   * generuje wykresy
   * zapisuje je jako PNG

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

---
