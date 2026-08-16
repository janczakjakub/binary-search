# Binary Search — Python

Opis algorytmów, złożoności obliczeniowej i benchmarku: [README główny](../README.md).

## Polski

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

Obie funkcje zwracają słownik `{'index': ..., 'comparisons': ...}`. Opcjonalny trzeci argument `compare_fn(a, b)` pozwala na niestandardowe porównywanie elementów.

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

---

## English

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

Both functions return `{'index': ..., 'comparisons': ...}`. An optional third argument `compare_fn(a, b)` allows custom element comparison.

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
