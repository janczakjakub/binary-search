#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "binary_search.h"
#include "simple_search.h"

static const int benchmark_sizes[] = { 100, 1000, 10000, 100000, 1000000 };
static const size_t benchmark_sizes_count = sizeof(benchmark_sizes) / sizeof(benchmark_sizes[0]);

typedef SearchResult (*SearchStrategy)(const int *, size_t, int, CompareFunc);

typedef struct {
    SearchResult result;
    double duration_ms;
} BenchmarkResult;

typedef struct {
    int size;
    int linear_comparisons;
    int binary_comparisons;
    double linear_ms;
    double binary_ms;
    char ratio[16];
} ResultRow;

static double now_ms(void) {
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        return 0.0;
    }

    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1000000.0;
}

static int *create_sorted_dataset(int size) {
    int *dataset = malloc((size_t)size * sizeof(int));

    if (dataset == NULL) {
        fprintf(stderr, "Failed to allocate dataset of size %d\n", size);
        exit(EXIT_FAILURE);
    }

    for (int index = 0; index < size; index++) {
        dataset[index] = index;
    }

    return dataset;
}

static BenchmarkResult run_single_benchmark(
    SearchStrategy strategy,
    const int *dataset,
    size_t length,
    int target
) {
    double start = now_ms();
    SearchResult result = strategy(dataset, length, target, NULL);
    double duration_ms = now_ms() - start;

    return (BenchmarkResult){ .result = result, .duration_ms = duration_ms };
}

static void print_results_table(const ResultRow *rows, size_t count) {
    printf(
        "n        | linear (comparisons) | binary (comparisons) | ratio   | "
        "linear (ms) | binary (ms)\n"
    );
    printf(
        "---------|----------------------|----------------------|---------|"
        "-------------|------------\n"
    );

    for (size_t index = 0; index < count; index++) {
        printf(
            "%-8d | %-20d | %-20d | %-7s | %-11.4f | %.4f\n",
            rows[index].size,
            rows[index].linear_comparisons,
            rows[index].binary_comparisons,
            rows[index].ratio,
            rows[index].linear_ms,
            rows[index].binary_ms
        );
    }
}

int main(void) {
    ResultRow rows[benchmark_sizes_count];

    printf("Binary Search vs Linear Search — complexity comparison\n\n");
    printf("Scenario: search for the last element (worst case for linear search)\n\n");

    for (size_t index = 0; index < benchmark_sizes_count; index++) {
        int size = benchmark_sizes[index];
        int *dataset = create_sorted_dataset(size);
        int target = size - 1;

        BenchmarkResult linear_result = run_single_benchmark(
            simple_search,
            dataset,
            (size_t)size,
            target
        );
        BenchmarkResult binary_result = run_single_benchmark(
            binary_search,
            dataset,
            (size_t)size,
            target
        );

        if (linear_result.result.index != binary_result.result.index) {
            fprintf(
                stderr,
                "Index mismatch at n=%d: linear=%d, binary=%d\n",
                size,
                linear_result.result.index,
                binary_result.result.index
            );
            free(dataset);
            return EXIT_FAILURE;
        }

        if (binary_result.result.comparisons > 0) {
            snprintf(
                rows[index].ratio,
                sizeof(rows[index].ratio),
                "~%dx",
                (int)lround(
                    (double)linear_result.result.comparisons /
                    (double)binary_result.result.comparisons
                )
            );
        } else {
            snprintf(rows[index].ratio, sizeof(rows[index].ratio), "N/A");
        }

        rows[index].size = size;
        rows[index].linear_comparisons = linear_result.result.comparisons;
        rows[index].binary_comparisons = binary_result.result.comparisons;
        rows[index].linear_ms = linear_result.duration_ms;
        rows[index].binary_ms = binary_result.duration_ms;

        free(dataset);
    }

    print_results_table(rows, benchmark_sizes_count);

    printf("\nSummary:\n");
    printf("- Linear search:  O(n)   — comparisons grow proportionally with array size\n");
    printf("- Binary search:  O(log n) — comparisons grow logarithmically\n");
    printf("- Binary search requires a sorted array; linear search works on any array\n");

    return EXIT_SUCCESS;
}
