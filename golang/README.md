# Binary Search — Go

Opis algorytmów, złożoności obliczeniowej i benchmarku: [README główny](../README.md).

## Polski

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

Obie funkcje zwracają strukturę `SearchResult{Index, Comparisons}`. Opcjonalny trzeci argument `compareFn CompareFunc` pozwala na niestandardowe porównywanie elementów. Przekaż `nil`, aby użyć `DefaultCompare`.

### Uruchomienie benchmarku

Z katalogu `golang/`:

```bash
go run .
```

Z katalogu głównego repozytorium:

```bash
go run -C golang .
```

---

## English

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

Both functions return `SearchResult{Index, Comparisons}`. An optional third argument `compareFn CompareFunc` allows custom element comparison. Pass `nil` to use `DefaultCompare`.

### Running the benchmark

From the `golang/` directory:

```bash
go run .
```

From the repository root:

```bash
go run -C golang .
```
