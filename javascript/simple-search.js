'use strict';

const { defaultCompare } = require('./binary-search');

/**
 * @typedef {import('./binary-search').SearchResult} SearchResult
 */

/**
 * Linear search through an array element by element.
 * Time complexity: O(n), space complexity: O(1).
 *
 * @param {number[]} array - Array to search
 * @param {number} target - Value to search for
 * @param {(a: number, b: number) => number} [compareFn=defaultCompare]
 * @returns {SearchResult}
 */
const simpleSearch = (array, target, compareFn = defaultCompare) => {
  if (!Array.isArray(array)) {
    throw new TypeError('array must be an array');
  }

  let comparisons = 0;

  for (let index = 0; index < array.length; index += 1) {
    comparisons += 1;
    if (compareFn(array[index], target) === 0) {
      return { index, comparisons };
    }
  }

  return { index: -1, comparisons };
};

module.exports = { simpleSearch };
