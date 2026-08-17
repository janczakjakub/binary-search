#include "binary_search.h"

int default_compare(int a, int b) {
    return a - b;
}

SearchResult binary_search(
    const int *sorted_array,
    size_t length,
    int target,
    CompareFunc compare_fn
) {
    if (compare_fn == NULL) {
        compare_fn = default_compare;
    }

    int left = 0;
    int right = (int)length - 1;
    int comparisons = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        int comparison = compare_fn(sorted_array[mid], target);

        if (comparison == 0) {
            return (SearchResult){ .index = mid, .comparisons = comparisons };
        }

        if (comparison < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return (SearchResult){ .index = -1, .comparisons = comparisons };
}
