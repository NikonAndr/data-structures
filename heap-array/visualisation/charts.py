import os
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = "results"
OUTPUT_DIR = "visualisation/plots"

STRUCTURES = {
    "ArrayPQ": "Array (unsorted)",
    "HeapPQ": "Heap (binary heap)"
}

STYLES = {
    "ArrayPQ": ("-", "o"),
    "HeapPQ": ("--", "s"),
}

def ensure_output_dir():
    os.makedirs(OUTPUT_DIR, exist_ok=True)


def load_csv(path):
    if not os.path.exists(path):
        return None
    return pd.read_csv(path)


def find_file(method_path, keyword):
    for file in os.listdir(method_path):
        if keyword in file:
            return os.path.join(method_path, file)
    return None


def plot_method(method):
    method_path = os.path.join(BASE_DIR, method)

    plt.figure(figsize=(8, 5))
    found = False

    for key, label in STRUCTURES.items():
        path = find_file(method_path, key)
        df = load_csv(path) if path else None

        if df is None:
            continue

        found = True

        time_us = df["time"] * 1e6
        linestyle, marker = STYLES[key]

        plt.plot(
            df["N"],
            time_us,
            linestyle=linestyle,
            marker=marker,
            markersize=5,
            linewidth=2,
            label=label
        )

    if not found:
        print(f"[SKIP] {method} (no data)")
        return

    plt.title(f"{method}()", fontsize=16, fontweight="bold")
    plt.xlabel("N (size)", fontsize=12)
    plt.ylabel("time [µs]", fontsize=12)
    plt.grid(True)
    plt.legend()
    plt.tight_layout()

    output_path = os.path.join(OUTPUT_DIR, f"{method}.png")
    plt.savefig(output_path, dpi=300)
    print(f"[PLOT] {method} → {output_path}")


def plot_heap_only(method):
    method_path = os.path.join(BASE_DIR, method)
    path = find_file(method_path, "HeapPQ")
    df = load_csv(path) if path else None

    if df is None:
        print(f"[SKIP] {method} heap-only (no data)")
        return

    time_us = df["time"] * 1e6

    plt.figure(figsize=(8, 5))
    plt.plot(
        df["N"],
        time_us,
        linestyle="--",
        marker="s",
        markersize=5,
        linewidth=2,
        label="Heap (binary heap)"
    )

    plt.title(f"{method}() — Heap only", fontsize=16, fontweight="bold")
    plt.xlabel("N (size)", fontsize=12)
    plt.ylabel("time [µs]", fontsize=12)
    plt.grid(True)
    plt.legend()
    plt.tight_layout()

    output_path = os.path.join(OUTPUT_DIR, f"{method}_heap_only.png")
    plt.savefig(output_path, dpi=300)
    print(f"[PLOT] {method} heap-only → {output_path}")


def get_methods():
    if not os.path.exists(BASE_DIR):
        return []

    return [
        d for d in os.listdir(BASE_DIR)
        if os.path.isdir(os.path.join(BASE_DIR, d))
    ]


def main():
    ensure_output_dir()

    methods = sorted(get_methods())

    if not methods:
        print("No benchmark results found")
        return

    for method in methods:
        plot_method(method)

    for method in ["extract_max", "peek"]:
        if method in methods:
            plot_heap_only(method)


if __name__ == "__main__":
    main()