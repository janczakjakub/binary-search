'use strict';

const { performance } = require('node:perf_hooks');
const { binarySearch } = require('./binary-search');
const { simpleSearch } = require('./simple-search');

/** @typedef {(array: number[], target: number) => import('./binary-search').SearchResult} SearchStrategy */

const BENCHMARK_SIZES = [100, 1_000, 10_000, 100_000, 1_000_000];

const SEARCH_STRATEGIES = [
  { name: 'linear', fn: simpleSearch },
  { name: 'binary', fn: binarySearch },
];

/**
 * Creates a sorted dataset of consecutive integers [0, 1, ..., size - 1].
 * @param {number} size
 * @returns {number[]}
 */
const createSortedDataset = (size) =>
  Array.from({ length: size }, (_, index) => index);

/**
 * Runs a single search strategy and measures comparisons and elapsed time.
 * @param {SearchStrategy} strategy
 * @param {number[]} dataset
 * @param {number} target
 * @returns {{ index: number, comparisons: number, durationMs: number }}
 */
const runSingleBenchmark = (strategy, dataset, target) => {
  const start = performance.now();
  const result = strategy(dataset, target);
  const durationMs = performance.now() - start;

  return { ...result, durationMs };
};

/**
 * Formats benchmark rows into a console table.
 * @param {Array<{ size: number, linearComparisons: number, binaryComparisons: number, linearMs: number, binaryMs: number, ratio: string }>} rows
 * @returns {string}
 */
const formatResultsTable = (rows) => {
  const header =
    'n        | linear (comparisons) | binary (comparisons) | ratio   | linear (ms) | binary (ms)';
  const separator =
    '---------|----------------------|----------------------|---------|-------------|------------';

  const body = rows
    .map(
      ({ size, linearComparisons, binaryComparisons, ratio, linearMs, binaryMs }) =>
        `${String(size).padEnd(8)} | ${String(linearComparisons).padEnd(20)} | ${String(binaryComparisons).padEnd(20)} | ${ratio.padEnd(7)} | ${linearMs.toFixed(4).padEnd(11)} | ${binaryMs.toFixed(4)}`,
    )
    .join('\n');

  return `${header}\n${separator}\n${body}`;
};

/**
 * Executes benchmarks for all configured dataset sizes.
 * @returns {void}
 */
const main = () => {
  console.log('Binary Search vs Linear Search — complexity comparison\n');
  console.log('Scenario: search for the last element (worst case for linear search)\n');

  const rows = BENCHMARK_SIZES.map((size) => {
    const dataset = createSortedDataset(size);
    const target = size - 1;

    const linearResult = runSingleBenchmark(simpleSearch, dataset, target);
    const binaryResult = runSingleBenchmark(binarySearch, dataset, target);

    if (linearResult.index !== binaryResult.index) {
      throw new Error(
        `Index mismatch at n=${size}: linear=${linearResult.index}, binary=${binaryResult.index}`,
      );
    }

    const ratio =
      binaryResult.comparisons > 0
        ? `~${Math.round(linearResult.comparisons / binaryResult.comparisons)}x`
        : 'N/A';

    return {
      size,
      linearComparisons: linearResult.comparisons,
      binaryComparisons: binaryResult.comparisons,
      linearMs: linearResult.durationMs,
      binaryMs: binaryResult.durationMs,
      ratio,
    };
  });

  console.log(formatResultsTable(rows));
  console.log('\nSummary:');
  console.log('- Linear search:  O(n)   — comparisons grow proportionally with array size');
  console.log('- Binary search:  O(log n) — comparisons grow logarithmically');
  console.log('- Binary search requires a sorted array; linear search works on any array');
};

main();
