package main

type SearchResult struct {
	Index       int
	Comparisons int
}

type CompareFunc func(a, b int) int

func DefaultCompare(a, b int) int {
	return a - b
}

func BinarySearch(sortedArray []int, target int, compareFn CompareFunc) SearchResult {
	if compareFn == nil {
		compareFn = DefaultCompare
	}

	left := 0
	right := len(sortedArray) - 1
	comparisons := 0

	for left <= right {
		mid := left + (right-left)/2
		comparisons++
		comparison := compareFn(sortedArray[mid], target)

		if comparison == 0 {
			return SearchResult{Index: mid, Comparisons: comparisons}
		}

		if comparison < 0 {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return SearchResult{Index: -1, Comparisons: comparisons}
}
