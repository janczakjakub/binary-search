#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

typedef struct {
    int index;
    int comparisons;
} SearchResult;

typedef int (*CompareFunc)(int a, int b);

int default_compare(int a, int b);

SearchResult binary_search(
    const int *sorted_array,
    size_t length,
    int target,
    CompareFunc compare_fn
);

#endif
