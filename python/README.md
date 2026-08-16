# Binary Search — Python

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
python/
├── binary_search.py   # wyszukiwanie binarne
├── simple_search.py   # wyszukiwanie liniowe
├── run.py             # porównanie złożoności obu algorytmów
└── README.md
```

### Wymagania

- Python 3.9+
- Tylko biblioteka standardowa (brak zewnętrznych zależności)

### Użycie API

```python
from binary_search import binary_search
from simple_search import simple_search

data = [1, 3, 5, 7, 9, 11]

print(binary_search(data, 7))  # {'index': 3, 'comparisons': 3}
print(simple_search(data, 7))  # {'index': 3, 'comparisons': 4}
```

Obie funkcje zwracają słownik `{'index': ..., 'comparisons': ...}`:
- `index` — indeks znalezionego elementu lub `-1`, gdy brak w tablicy
- `comparisons` — liczba wykonanych porównań

Opcjonalny trzeci argument `compare_fn(a, b)` pozwala na niestandardowe porównywanie elementów (domyślnie porównanie numeryczne).

### Uruchomienie benchmarku

Z katalogu `python/`:

```bash
python3 run.py
```

Z katalogu głównego repozytorium:

```bash
python3 python/run.py
```

Na systemach, gdzie `python` wskazuje na Python 3, możesz użyć `python` zamiast `python3`.

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
python/
├── binary_search.py   # binary search implementation
├── simple_search.py   # linear search implementation
├── run.py             # complexity comparison benchmark
└── README.md
```

### Requirements

- Python 3.9+
- Standard library only (no external dependencies)

### API usage

```python
from binary_search import binary_search
from simple_search import simple_search

data = [1, 3, 5, 7, 9, 11]

print(binary_search(data, 7))  # {'index': 3, 'comparisons': 3}
print(simple_search(data, 7))  # {'index': 3, 'comparisons': 4}
```

Both functions return `{'index': ..., 'comparisons': ...}`:
- `index` — index of the found element, or `-1` if not present
- `comparisons` — number of comparisons performed

An optional third argument `compare_fn(a, b)` allows custom element comparison (numeric comparison by default).

### Running the benchmark

From the `python/` directory:

```bash
python3 run.py
```

From the repository root:

```bash
python3 python/run.py
```

On systems where `python` points to Python 3, you can use `python` instead of `python3`.

The script generates sorted arrays ranging from 100 to 1,000,000 elements, searches for the last element (worst case for linear search), and prints a table with comparison counts and execution times.
