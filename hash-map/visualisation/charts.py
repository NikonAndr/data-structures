import os
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = "results"
OUTPUT_DIR = "visualisation/plots"

STRUCTURES = {
    "AVL": "HashMapAVL",
    "Linear": "HashMapLinear",
    "List": "HashMapList"
}

STYLES = {
    "AVL":    ("-",  "o"),
    "Linear": ("--", "s"),
    "List":   ("-.", "D")
}

OPERATIONS = ["insert", "remove"]


def ensure_output_dir():
    os.makedirs(OUTPUT_DIR, exist_ok=True)


def load_csv(path):
    if not os.path.exists(path):
        return None
    return pd.read_csv(path)


def plot_operation(operation):
    op_path = os.path.join(BASE_DIR, operation)

    plt.figure(figsize=(8, 5))

    found = False

    for filename, label in STRUCTURES.items():
        path = os.path.join(op_path, f"{filename}.csv")
        df = load_csv(path)

        if df is None:
            print(f"[MISSING] {path}")
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
        print(f"[SKIP] {operation} (no data)")
        plt.close()
        return

    plt.title(f"Time complexity of {operation}()", fontsize=16, fontweight="bold")
    plt.xlabel("N (size)", fontsize=12, fontweight="bold")
    plt.ylabel("time [µs]", fontsize=12, fontweight="bold")

    plt.xticks(fontsize=10)
    plt.yticks(fontsize=10)

    plt.grid(True)

    plt.legend(
        loc="lower left",
        bbox_to_anchor=(0, -0.3),
        ncol=3
    )

    plt.tight_layout()

    output_path = os.path.join(OUTPUT_DIR, f"{operation}.png")
    plt.savefig(output_path, dpi=300, bbox_inches="tight")
    plt.close()

    print(f"[PLOT] {operation} → saved to {output_path}")


def main():
    ensure_output_dir()

    for operation in OPERATIONS:
        plot_operation(operation)


if __name__ == "__main__":
    main()