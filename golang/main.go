package main

import (
	"fmt"
	"math"
	"time"
)

var benchmarkSizes = []int{100, 1_000, 10_000, 100_000, 1_000_000}

type benchmarkResult struct {
	SearchResult
	DurationMs float64
}

type resultRow struct {
	size               int
	linearComparisons  int
	binaryComparisons  int
	linearMs           float64
	binaryMs           float64
	ratio              string
}

type searchStrategy func([]int, int) SearchResult

func createSortedDataset(size int) []int {
	dataset := make([]int, size)
	for i := range dataset {
		dataset[i] = i
	}
	return dataset
}

func runSingleBenchmark(strategy searchStrategy, dataset []int, target int) benchmarkResult {
	start := time.Now()
	result := strategy(dataset, target)
	durationMs := time.Since(start).Seconds() * 1000

	return benchmarkResult{
		SearchResult: result,
		DurationMs:   durationMs,
	}
}

func formatResultsTable(rows []resultRow) string {
	header := "n        | linear (comparisons) | binary (comparisons) | ratio   | linear (ms) | binary (ms)"
	separator := "---------|----------------------|----------------------|---------|-------------|------------"

	output := header + "\n" + separator + "\n"
	for _, row := range rows {
		output += fmt.Sprintf(
			"%-8d | %-20d | %-20d | %-7s | %-11.4f | %.4f\n",
			row.size,
			row.linearComparisons,
			row.binaryComparisons,
			row.ratio,
			row.linearMs,
			row.binaryMs,
		)
	}

	return output
}

func main() {
	fmt.Println("Binary Search vs Linear Search — complexity comparison\n")
	fmt.Println("Scenario: search for the last element (worst case for linear search)\n")

	rows := make([]resultRow, 0, len(benchmarkSizes))

	for _, size := range benchmarkSizes {
		dataset := createSortedDataset(size)
		target := size - 1

		linearResult := runSingleBenchmark(
			func(data []int, value int) SearchResult { return SimpleSearch(data, value, nil) },
			dataset,
			target,
		)
		binaryResult := runSingleBenchmark(
			func(data []int, value int) SearchResult { return BinarySearch(data, value, nil) },
			dataset,
			target,
		)

		if linearResult.Index != binaryResult.Index {
			panic(fmt.Sprintf(
				"Index mismatch at n=%d: linear=%d, binary=%d",
				size,
				linearResult.Index,
				binaryResult.Index,
			))
		}

		ratio := "N/A"
		if binaryResult.Comparisons > 0 {
			ratio = fmt.Sprintf(
				"~%dx",
				int(math.Round(float64(linearResult.Comparisons)/float64(binaryResult.Comparisons))),
			)
		}

		rows = append(rows, resultRow{
			size:              size,
			linearComparisons: linearResult.Comparisons,
			binaryComparisons: binaryResult.Comparisons,
			linearMs:          linearResult.DurationMs,
			binaryMs:          binaryResult.DurationMs,
			ratio:             ratio,
		})
	}

	fmt.Print(formatResultsTable(rows))
	fmt.Println("\nSummary:")
	fmt.Println("- Linear search:  O(n)   — comparisons grow proportionally with array size")
	fmt.Println("- Binary search:  O(log n) — comparisons grow logarithmically")
	fmt.Println("- Binary search requires a sorted array; linear search works on any array")
}
