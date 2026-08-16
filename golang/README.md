# Binary Search — Go

## Polski

### Opis

**Wyszukiwanie binarne** (binary search) to algorytm znajdujący element w **posortowanej** tablicy poprzez wielokrotne dzielenie przeszukiwanego zakresu na pół. W każdym kroku porównuje element środkowy z wartością docelową i odrzuca połowę tablicy, w której elementu na pewno nie ma.

**Wyszukiwanie liniowe** (linear / simple search) przechodzi tablicę element po elemencie od początku do końca. Działa na dowolnej tablicy — nie wymaga sortowania — ale jest wolniejsze przy dużych zbiorach danych.

### Złożoność obliczeniowa

| Algorytm          | Czasowa   | Pamięciowa | Wymagania          |
|-------------------|-----------|------------|--------------------|
| Wyszukiwanie liniowe | O(n)   | O(1)       | brak               |
| Wyszukiwanie binarne | O(log n) | O(1)     | posortowana tablica |

### Struktura plików

```
golang/
├── binary_search.go   # wyszukiwanie binarne
├── simple_search.go   # wyszukiwanie liniowe
├── main.go            # porównanie złożoności obu algorytmów
├── go.mod
└── README.md
```

### Wymagania

- Go 1.21+
- Tylko biblioteka standardowa (brak zewnętrznych zależności)

### Użycie API

```go
data := []int{1, 3, 5, 7, 9, 11}

fmt.Println(BinarySearch(data, 7)) // {3 3}
fmt.Println(SimpleSearch(data, 7)) // {3 4}
```

Obie funkcje zwracają strukturę `SearchResult{Index, Comparisons}`:
- `Index` — indeks znalezionego elementu lub `-1`, gdy brak w tablicy
- `Comparisons` — liczba wykonanych porównań

Opcjonalny trzeci argument `compareFn CompareFunc` pozwala na niestandardowe porównywanie elementów (domyślnie porównanie numeryczne). Przekaż `nil`, aby użyć `DefaultCompare`.

### Uruchomienie benchmarku

Z katalogu `golang/`:

```bash
go run .
```

Z katalogu głównego repozytorium:

```bash
go run -C golang .
```

Skrypt generuje posortowane tablice o rozmiarach od 100 do 1 000 000 elementów, wyszukuje ostatni element (najgorszy przypadek dla wyszukiwania liniowego) i wyświetla tabelę z liczbą porównań oraz czasem wykonania.

---

## English

### Description

**Binary search** is an algorithm that finds an element in a **sorted** array by repeatedly dividing the search interval in half. At each step it compares the middle element with the target value and discards the half where the element cannot exist.

**Linear search** (simple search) scans the array element by element from start to end. It works on any array — no sorting required — but is slower on large datasets.

### Computational complexity

| Algorithm     | Time       | Space | Requirements  |
|---------------|------------|-------|---------------|
| Linear search | O(n)       | O(1)  | none          |
| Binary search | O(log n)   | O(1)  | sorted array  |

### File structure

```
golang/
├── binary_search.go   # binary search implementation
├── simple_search.go   # linear search implementation
├── main.go            # complexity comparison benchmark
├── go.mod
└── README.md
```

### Requirements

- Go 1.21+
- Standard library only (no external dependencies)

### API usage

```go
data := []int{1, 3, 5, 7, 9, 11}

fmt.Println(BinarySearch(data, 7)) // {3 3}
fmt.Println(SimpleSearch(data, 7)) // {3 4}
```

Both functions return `SearchResult{Index, Comparisons}`:
- `Index` — index of the found element, or `-1` if not present
- `Comparisons` — number of comparisons performed

An optional third argument `compareFn CompareFunc` allows custom element comparison (numeric comparison by default). Pass `nil` to use `DefaultCompare`.

### Running the benchmark

From the `golang/` directory:

```bash
go run .
```

From the repository root:

```bash
go run -C golang .
```

The script generates sorted arrays ranging from 100 to 1,000,000 elements, searches for the last element (worst case for linear search), and prints a table with comparison counts and execution times.
