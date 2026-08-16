'use strict';

/**
 * @typedef {Object} SearchResult
 * @property {number} index - Index of the found element, or -1 if not found
 * @property {number} comparisons - Number of comparisons performed
 */

/**
 * Default numeric comparison function.
 * @param {number} a
 * @param {number} b
 * @returns {number}
 */
const defaultCompare = (a, b) => a - b;

/**
 * Binary search on a sorted array.
 * Time complexity: O(log n), space complexity: O(1).
 *
 * @param {number[]} sortedArray - Array sorted in ascending order according to compareFn
 * @param {number} target - Value to search for
 * @param {(a: number, b: number) => number} [compareFn=defaultCompare]
 * @returns {SearchResult}
 */
const binarySearch = (sortedArray, target, compareFn = defaultCompare) => {
  if (!Array.isArray(sortedArray)) {
    throw new TypeError('sortedArray must be an array');
  }

  let left = 0;
  let right = sortedArray.length - 1;
  let comparisons = 0;

  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    comparisons += 1;
    const comparison = compareFn(sortedArray[mid], target);

    if (comparison === 0) {
      return { index: mid, comparisons };
    }

    if (comparison < 0) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return { index: -1, comparisons };
};

module.exports = { binarySearch, defaultCompare };
