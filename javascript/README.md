# Binary Search — JavaScript

Opis algorytmów, złożoności obliczeniowej i benchmarku: [README główny](../README.md).

## Polski

### Struktura plików

```
javascript/
├── binary-search.js   # wyszukiwanie binarne
├── simple-search.js   # wyszukiwanie liniowe
├── run.js             # porównanie złożoności obu algorytmów
└── README.md
```

### Wymagania

- Node.js (wbudowany moduł `node:perf_hooks`)

### Użycie API

```javascript
const { binarySearch } = require('./binary-search');
const { simpleSearch } = require('./simple-search');

const data = [1, 3, 5, 7, 9, 11];

console.log(binarySearch(data, 7));  // { index: 3, comparisons: 3 }
console.log(simpleSearch(data, 7));  // { index: 3, comparisons: 4 }
```

Obie funkcje zwracają obiekt `{ index, comparisons }`. Opcjonalny trzeci argument `compareFn(a, b)` pozwala na niestandardowe porównywanie elementów.

### Uruchomienie benchmarku

Z katalogu `javascript/`:

```bash
node run.js
```

Z katalogu głównego repozytorium:

```bash
node javascript/run.js
```

---

## English

### File structure

```
javascript/
├── binary-search.js   # binary search implementation
├── simple-search.js   # linear search implementation
├── run.js             # complexity comparison benchmark
└── README.md
```

### Requirements

- Node.js (built-in `node:perf_hooks` module)

### API usage

```javascript
const { binarySearch } = require('./binary-search');
const { simpleSearch } = require('./simple-search');

const data = [1, 3, 5, 7, 9, 11];

console.log(binarySearch(data, 7));  // { index: 3, comparisons: 3 }
console.log(simpleSearch(data, 7));  // { index: 3, comparisons: 4 }
```

Both functions return `{ index, comparisons }`. An optional third argument `compareFn(a, b)` allows custom element comparison.

### Running the benchmark

From the `javascript/` directory:

```bash
node run.js
```

From the repository root:

```bash
node javascript/run.js
```
