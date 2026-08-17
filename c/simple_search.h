#ifndef SIMPLE_SEARCH_H
#define SIMPLE_SEARCH_H

#include "binary_search.h"

SearchResult simple_search(
    const int *array,
    size_t length,
    int target,
    CompareFunc compare_fn
);

#endif
