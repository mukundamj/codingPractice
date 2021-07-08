#pragma once

#include <vector>

namespace Sorting {

    const std::vector<int> countSmaller(const std::vector<int>& numbers);
    void mergeSort(const std::vector<int>& numbers, std::vector<int>& indices, std::vector<int>& countOfSmallerValues, const int start, const int end);

}
