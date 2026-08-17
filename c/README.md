# Binary Search — C

Opis algorytmów, złożoności obliczeniowej i benchmarku: [README główny](../README.md).

## Polski

### Struktura plików

```
c/
├── binary_search.h    # nagłówek wyszukiwania binarnego
├── binary_search.c    # wyszukiwanie binarne
├── simple_search.h    # nagłówek wyszukiwania liniowego
├── simple_search.c    # wyszukiwanie liniowe
├── main.c             # porównanie złożoności obu algorytmów
├── Makefile
└── README.md
```

### Wymagania

- Kompilator C z obsługą C11 (np. GCC, Clang)
- Biblioteka standardowa C (brak zewnętrznych zależności)

### Użycie API

```c
#include "binary_search.h"
#include "simple_search.h"

int data[] = {1, 3, 5, 7, 9, 11};
size_t length = sizeof(data) / sizeof(data[0]);

SearchResult binary = binary_search(data, length, 7, NULL);
SearchResult linear = simple_search(data, length, 7, NULL);

printf("binary: index=%d, comparisons=%d\n", binary.index, binary.comparisons);
printf("linear: index=%d, comparisons=%d\n", linear.index, linear.comparisons);
```

Obie funkcje zwracają strukturę `SearchResult` z polami `index` i `comparisons`. Opcjonalny argument `compare_fn` pozwala na niestandardowe porównywanie elementów. Przekaż `NULL`, aby użyć `default_compare`.

### Uruchomienie benchmarku

Z katalogu `c/` (Makefile):

```bash
make run
```

Z katalogu `c/` (kompilacja ręczna):

```bash
cc -Wall -Wextra -std=c11 -O2 -o benchmark main.c binary_search.c simple_search.c -lm
./benchmark
```

Z katalogu głównego repozytorium:

```bash
make -C c run
```

---

## English

### File structure

```
c/
├── binary_search.h    # binary search header
├── binary_search.c    # binary search implementation
├── simple_search.h    # linear search header
├── simple_search.c    # linear search implementation
├── main.c             # complexity comparison benchmark
├── Makefile
└── README.md
```

### Requirements

- C11-compatible compiler (e.g. GCC, Clang)
- C standard library only (no external dependencies)

### API usage

```c
#include "binary_search.h"
#include "simple_search.h"

int data[] = {1, 3, 5, 7, 9, 11};
size_t length = sizeof(data) / sizeof(data[0]);

SearchResult binary = binary_search(data, length, 7, NULL);
SearchResult linear = simple_search(data, length, 7, NULL);

printf("binary: index=%d, comparisons=%d\n", binary.index, binary.comparisons);
printf("linear: index=%d, comparisons=%d\n", linear.index, linear.comparisons);
```

Both functions return a `SearchResult` struct with `index` and `comparisons`. An optional `compare_fn` argument allows custom element comparison. Pass `NULL` to use `default_compare`.

### Running the benchmark

From the `c/` directory (Makefile):

```bash
make run
```

From the `c/` directory (manual build):

```bash
cc -Wall -Wextra -std=c11 -O2 -o benchmark main.c binary_search.c simple_search.c -lm
./benchmark
```

From the repository root:

```bash
make -C c run
```
