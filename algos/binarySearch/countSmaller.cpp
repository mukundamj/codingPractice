#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> countSmaller(vector<int>&); 
    void merge_sort(vector<int>&, vector<int>&, vector<int>&, int, int); 
};

void Solution::merge_sort(vector<int>& result, vector<int>& indices, vector<int>& nums, int start, int end) {
  if (end == start) return;
  int mid = start + (end - start) / 2;   
  merge_sort(result, indices, nums, start, mid);
  merge_sort(result, indices, nums, mid + 1, end);
  int i = start, j = mid + 1;
  int count = 0;
  vector<int> sortedIndices;
  while (i <= mid && j <= end) {
    if (nums[indices[i]] <= nums[indices[j]]) {
      result[indices[i]] += count;
      sortedIndices.push_back(indices[i++]);
    }
    else {
      count++;
      sortedIndices.push_back(indices[j++]);
    }
  }
  while (i <= mid) {
    result[indices[i]] += count;
    sortedIndices.push_back(indices[i++]);
  }
  while (j <= end) { 
    sortedIndices.push_back(indices[j++]);
  }
  move (sortedIndices.begin(), sortedIndices.end(), indices.begin() + start);
  printf("Partial sorted array for start = %d, end = %d\n", start, end);
  for (int i : indices) printf("%d ", nums[i]);
  printf("Partial result for start = %d, end = %d\n", start, end);
  for (int i : result) printf("%d ", i);
  cout << endl;
}

vector<int> Solution::countSmaller(vector<int>& nums) {
  vector<int> result(nums.size(), 0);
  vector<int> indices(nums.size(), 0); //Index is sorted instead of the actual array so that while sorting counts can be updated in the results array
  iota(indices.begin(), indices.end(), 0);
  merge_sort(result, indices, nums, 0, nums.size() - 1);
  return result;
}

//For each index of the input array count the number of values to the right which is less than itself  
int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums = {6, 4, 1, 8, 7, 5, 2, 9};
  vector<int> result = S.countSmaller(nums);
  for (int i : result) printf("%d ",i); 
  cout << endl;
  return 0;
}

