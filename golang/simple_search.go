package main

func SimpleSearch(array []int, target int, compareFn CompareFunc) SearchResult {
	if compareFn == nil {
		compareFn = DefaultCompare
	}

	comparisons := 0

	for index, value := range array {
		comparisons++
		if compareFn(value, target) == 0 {
			return SearchResult{Index: index, Comparisons: comparisons}
		}
	}

	return SearchResult{Index: -1, Comparisons: comparisons}
}
