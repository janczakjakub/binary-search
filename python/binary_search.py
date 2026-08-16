from typing import Callable, TypedDict


class SearchResult(TypedDict):
    index: int
    comparisons: int


def default_compare(a: int, b: int) -> int:
    return a - b


def binary_search(
    sorted_array: list[int],
    target: int,
    compare_fn: Callable[[int, int], int] = default_compare,
) -> SearchResult:
    if not isinstance(sorted_array, list):
        raise TypeError("sorted_array must be a list")

    left = 0
    right = len(sorted_array) - 1
    comparisons = 0

    while left <= right:
        mid = left + (right - left) // 2
        comparisons += 1
        comparison = compare_fn(sorted_array[mid], target)

        if comparison == 0:
            return {"index": mid, "comparisons": comparisons}

        if comparison < 0:
            left = mid + 1
        else:
            right = mid - 1

    return {"index": -1, "comparisons": comparisons}
