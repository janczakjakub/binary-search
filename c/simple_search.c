#include "simple_search.h"

SearchResult simple_search(
    const int *array,
    size_t length,
    int target,
    CompareFunc compare_fn
) {
    if (compare_fn == NULL) {
        compare_fn = default_compare;
    }

    int comparisons = 0;

    for (size_t index = 0; index < length; index++) {
        comparisons++;
        if (compare_fn(array[index], target) == 0) {
            return (SearchResult){ .index = (int)index, .comparisons = comparisons };
        }
    }

    return (SearchResult){ .index = -1, .comparisons = comparisons };
}
