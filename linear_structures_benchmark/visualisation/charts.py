import os
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = "results"
OUTPUT_DIR = "visualisation/plots"

STRUCTURES = {
    "array": "ArrayList",
    "singly": "SinglyLinkedList",
    "doubly": "DoublyLinkedList"
}

STYLES = {
    "array": ("-", "o"),   
    "singly": ("--", "s"), 
    "doubly": ("-.", "D")   
}

LOG_METHODS = {"push_front", "pop_back", "pop_front"}


def ensure_output_dir():
    os.makedirs(OUTPUT_DIR, exist_ok=True)


def load_csv(path):
    if not os.path.exists(path):
        return None
    return pd.read_csv(path)


def plot_method(method):
    method_path = os.path.join(BASE_DIR, method)

    plt.figure(figsize=(8, 5))

    found = False

    for filename, label in STRUCTURES.items():
        path = os.path.join(method_path, f"{filename}.csv")
        df = load_csv(path)

        if df is None:
            continue

        found = True

        time_us = df["time"] * 1e6

        linestyle, marker = STYLES[filename]

        plt.plot(
            df["N"],
            time_us,
            linestyle=linestyle,
            marker=marker,
            markersize=6,
            linewidth=2,
            label=label
        )

    if not found:
        print(f"[SKIP] {method} (no data)")
        return

    plt.title(f"Time complexity of {method}() method", fontsize=16, fontweight="bold")
    plt.xlabel("N (size)", fontsize=12, fontweight="bold")
    plt.ylabel("time [µs]", fontsize=12, fontweight="bold")

    plt.xticks(fontsize=10)
    plt.yticks(fontsize=10)

    if method in LOG_METHODS:
        plt.yscale("log")

    plt.grid(True)

    plt.legend(
        loc="lower left",
        bbox_to_anchor=(0, -0.35),
        ncol=3
    )

    plt.tight_layout()

    # save to a file
    output_path = os.path.join(OUTPUT_DIR, f"{method}.png")
    plt.savefig(output_path, dpi=300, bbox_inches="tight")

    print(f"[PLOT] {method} → saved to {output_path}")


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


if __name__ == "__main__":
    main()