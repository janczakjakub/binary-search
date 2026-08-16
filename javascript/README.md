# Binary Search — JavaScript

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
javascript/
├── binary-search.js   # wyszukiwanie binarne
├── simple-search.js   # wyszukiwanie liniowe
├── run.js             # porównanie złożoności obu algorytmów
└── README.md
```

### Użycie API

```javascript
const { binarySearch } = require('./binary-search');
const { simpleSearch } = require('./simple-search');

const data = [1, 3, 5, 7, 9, 11];

console.log(binarySearch(data, 7));  // { index: 3, comparisons: 3 }
console.log(simpleSearch(data, 7));  // { index: 3, comparisons: 4 }
```

Obie funkcje zwracają obiekt `{ index, comparisons }`:
- `index` — indeks znalezionego elementu lub `-1`, gdy brak w tablicy
- `comparisons` — liczba wykonanych porównań

Opcjonalny trzeci argument `compareFn(a, b)` pozwala na niestandardowe porównywanie elementów (domyślnie porównanie numeryczne).

### Uruchomienie benchmarku

Z katalogu `javascript/`:

```bash
node run.js
```

Z katalogu głównego repozytorium:

```bash
node javascript/run.js
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
javascript/
├── binary-search.js   # binary search implementation
├── simple-search.js   # linear search implementation
├── run.js             # complexity comparison benchmark
└── README.md
```

### API usage

```javascript
const { binarySearch } = require('./binary-search');
const { simpleSearch } = require('./simple-search');

const data = [1, 3, 5, 7, 9, 11];

console.log(binarySearch(data, 7));  // { index: 3, comparisons: 3 }
console.log(simpleSearch(data, 7));  // { index: 3, comparisons: 4 }
```

Both functions return `{ index, comparisons }`:
- `index` — index of the found element, or `-1` if not present
- `comparisons` — number of comparisons performed

An optional third argument `compareFn(a, b)` allows custom element comparison (numeric comparison by default).

### Running the benchmark

From the `javascript/` directory:

```bash
node run.js
```

From the repository root:

```bash
node javascript/run.js
```

The script generates sorted arrays ranging from 100 to 1,000,000 elements, searches for the last element (worst case for linear search), and prints a table with comparison counts and execution times.
