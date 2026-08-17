# Binary Search

Implementacje wyszukiwania binarnego i liniowego w kilku językach programowania, z benchmarkiem porównującym złożoność obu algorytmów.

## Polski

### Opis

**Wyszukiwanie binarne** (binary search) to algorytm znajdujący element w **posortowanej** tablicy poprzez wielokrotne dzielenie przeszukiwanego zakresu na pół. W każdym kroku porównuje element środkowy z wartością docelową i odrzuca połowę tablicy, w której elementu na pewno nie ma.

**Wyszukiwanie liniowe** (linear / simple search) przechodzi tablicę element po elemencie od początku do końca. Działa na dowolnej tablicy — nie wymaga sortowania — ale jest wolniejsze przy dużych zbiorach danych.

### Złożoność obliczeniowa

| Algorytm             | Czasowa  | Pamięciowa | Wymagania         |
|----------------------|----------|------------|-------------------|
| Wyszukiwanie liniowe | O(n)     | O(1)       | brak              |
| Wyszukiwanie binarne | O(log n) | O(1)       | posortowana tablica |

### Wspólne API

Każda implementacja udostępnia dwie funkcje wyszukiwania. Obie zwracają wynik zawierający:

- `index` — indeks znalezionego elementu lub `-1`, gdy brak w tablicy
- `comparisons` — liczba wykonanych porównań

Opcjonalny argument funkcji porównującej pozwala na niestandardowe porównywanie elementów (domyślnie porównanie numeryczne).

### Benchmark

Skrypt benchmarku generuje posortowane tablice o rozmiarach od 100 do 1 000 000 elementów, wyszukuje **ostatni** element (najgorszy przypadek dla wyszukiwania liniowego) i wyświetla tabelę z liczbą porównań oraz czasem wykonania.

### Implementacje

| Język      | Katalog       | Dokumentacja                    |
|------------|---------------|---------------------------------|
| JavaScript | `javascript/` | [javascript/README.md](javascript/README.md) |
| Python     | `python/`     | [python/README.md](python/README.md)       |
| Go         | `golang/`     | [golang/README.md](golang/README.md)       |
| C          | `c/`          | [c/README.md](c/README.md)                 |

---

## English

### Description

**Binary search** is an algorithm that finds an element in a **sorted** array by repeatedly dividing the search interval in half. At each step it compares the middle element with the target value and discards the half where the element cannot exist.

**Linear search** (simple search) scans the array element by element from start to end. It works on any array — no sorting required — but is slower on large datasets.

### Computational complexity

| Algorithm     | Time     | Space | Requirements  |
|---------------|----------|-------|---------------|
| Linear search | O(n)     | O(1)  | none          |
| Binary search | O(log n) | O(1)  | sorted array  |

### Common API

Each implementation exposes two search functions. Both return a result containing:

- `index` — index of the found element, or `-1` if not present
- `comparisons` — number of comparisons performed

An optional compare function argument allows custom element comparison (numeric comparison by default).

### Benchmark

The benchmark script generates sorted arrays ranging from 100 to 1,000,000 elements, searches for the **last** element (worst case for linear search), and prints a table with comparison counts and execution times.

### Implementations

| Language   | Directory     | Documentation                   |
|------------|---------------|---------------------------------|
| JavaScript | `javascript/` | [javascript/README.md](javascript/README.md) |
| Python     | `python/`     | [python/README.md](python/README.md)       |
| Go         | `golang/`     | [golang/README.md](golang/README.md)       |
| C          | `c/`          | [c/README.md](c/README.md)                 |
