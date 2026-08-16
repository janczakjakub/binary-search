import time
from typing import Callable

from binary_search import SearchResult, binary_search
from simple_search import simple_search

BENCHMARK_SIZES = [100, 1_000, 10_000, 100_000, 1_000_000]

SearchStrategy = Callable[[list[int], int], SearchResult]


def create_sorted_dataset(size: int) -> list[int]:
    return list(range(size))


def run_single_benchmark(
    strategy: SearchStrategy,
    dataset: list[int],
    target: int,
) -> SearchResult:
    start = time.perf_counter()
    result = strategy(dataset, target)
    duration_ms = (time.perf_counter() - start) * 1000

    return {**result, "duration_ms": duration_ms}


def format_results_table(rows: list[dict]) -> str:
    header = (
        "n        | linear (comparisons) | binary (comparisons) | ratio   | "
        "linear (ms) | binary (ms)"
    )
    separator = (
        "---------|----------------------|----------------------|---------|"
        "-------------|------------"
    )

    body_lines = []
    for row in rows:
        body_lines.append(
            f"{str(row['size']).ljust(8)} | "
            f"{str(row['linear_comparisons']).ljust(20)} | "
            f"{str(row['binary_comparisons']).ljust(20)} | "
            f"{row['ratio'].ljust(7)} | "
            f"{row['linear_ms']:.4f}".ljust(11)
            + " | "
            + f"{row['binary_ms']:.4f}"
        )

    return f"{header}\n{separator}\n" + "\n".join(body_lines)


def main() -> None:
    print("Binary Search vs Linear Search — complexity comparison\n")
    print("Scenario: search for the last element (worst case for linear search)\n")

    rows = []
    for size in BENCHMARK_SIZES:
        dataset = create_sorted_dataset(size)
        target = size - 1

        linear_result = run_single_benchmark(simple_search, dataset, target)
        binary_result = run_single_benchmark(binary_search, dataset, target)

        if linear_result["index"] != binary_result["index"]:
            raise ValueError(
                f"Index mismatch at n={size}: "
                f"linear={linear_result['index']}, binary={binary_result['index']}"
            )

        ratio = (
            f"~{round(linear_result['comparisons'] / binary_result['comparisons'])}x"
            if binary_result["comparisons"] > 0
            else "N/A"
        )

        rows.append(
            {
                "size": size,
                "linear_comparisons": linear_result["comparisons"],
                "binary_comparisons": binary_result["comparisons"],
                "linear_ms": linear_result["duration_ms"],
                "binary_ms": binary_result["duration_ms"],
                "ratio": ratio,
            }
        )

    print(format_results_table(rows))
    print("\nSummary:")
    print("- Linear search:  O(n)   — comparisons grow proportionally with array size")
    print("- Binary search:  O(log n) — comparisons grow logarithmically")
    print("- Binary search requires a sorted array; linear search works on any array")


if __name__ == "__main__":
    main()
