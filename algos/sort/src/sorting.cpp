#include "sorting.h"
#include <algorithm>
#include <numeric>

namespace Sorting {

/*
 Objective: For each index of the input array count the number of values to the right which is less than itself.
 And the return value is a vector which contains the count.

 Algorithm: The idea is to sort the indices representing the array instead of the array itself. If we sort the
 array itself we will loose the original positional information, but we want to preserve it in order to update
 the count.
 
 To count the number of smaller values to the right merge sort approach is used because it makes the counting
 easier. If a number in the right sub array is smaller than a number in left sub array then the count for the 
 number in left sub array should be incremented.

 Time complexity of the algorithm T(n) = 2*T(n/2) + constant
               This reduces to to T(n) = O(n*log₂n)

 Example: If n = 16, log₂16 = 4, so T(16) = O(16*4) = O(64)
*/
const std::vector<int> countSmaller(const std::vector<int>& numbers) {

  std::vector<int> indices(numbers.size(), 0);
  //std::iota fills a range with successive increments of the starting value
  std::iota(indices.begin(), indices.end(), 0);

  std::vector<int> countOfSmallerValues(numbers.size(), 0);

  mergeSort(numbers, indices, countOfSmallerValues, 0, numbers.size() - 1);

  return countOfSmallerValues;
}

// This merge sort algorithm is used by the countSmaller function
void mergeSort(const std::vector<int>& numbers, std::vector<int>& indices, std::vector<int>& countOfSmallerValues, const int start, const int end) {
  if (start >= end) return;    //The > condition kicks in when the numbers.size() == 0, in which case start = 0 and end = -1

  int mid = start + (end - start) / 2;   
  mergeSort(numbers, indices, countOfSmallerValues, start, mid);
  mergeSort(numbers, indices, countOfSmallerValues, mid + 1, end);

  int i = start, j = mid + 1;
  int count = 0;
  std::vector<int> sortedIndices;

  while (i <= mid && j <= end) {
    if (numbers[indices[i]] <= numbers[indices[j]]) {
      countOfSmallerValues[indices[i]] += count;
      sortedIndices.push_back(indices[i++]);
    }
    else {
      count++;
      sortedIndices.push_back(indices[j++]);
    }
  }

  while (i <= mid) {
    countOfSmallerValues[indices[i]] += count;
    sortedIndices.push_back(indices[i++]);
  }

  while (j <= end) { 
    sortedIndices.push_back(indices[j++]);
  }

  std::move(sortedIndices.begin(), sortedIndices.end(), indices.begin() + start);
}

}    // end of the Sorting namespace
