from typing import Callable

from binary_search import SearchResult, default_compare


def simple_search(
    array: list[int],
    target: int,
    compare_fn: Callable[[int, int], int] = default_compare,
) -> SearchResult:
    if not isinstance(array, list):
        raise TypeError("array must be a list")

    comparisons = 0

    for index, value in enumerate(array):
        comparisons += 1
        if compare_fn(value, target) == 0:
            return {"index": index, "comparisons": comparisons}

    return {"index": -1, "comparisons": comparisons}
