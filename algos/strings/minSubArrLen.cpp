#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int, vector<int>&); 
};

//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous 
//subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//For example, given the array [2,3,1,2,4,3] and s = 7,
//the subarray [4,3] has the minimal length under the problem constraint
int Solution::minSubArrayLen(int s, vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int len = INT_MAX, start = 0, end = 0, sum = 0;
  while (end < nums.size() && start <= end) { //Seems like the condition start <= end is redundant; test it and remove if not required.
    sum += nums[end];
    if (sum < s) {
      end++;
    }
    if (sum > s) {
      len = min(len, (end - start + 1));
      sum -= nums[start++]; 
      sum -= nums[end]; 
    }
    if (sum == s) {
      len = min(len, (end - start + 1));
      sum -= nums[start++]; 
      end++;
    }
  }
  len = (len == INT_MAX) ? 0 : len;
  return len;
}

int main(int argc, const char * argv[]) {
  Solution S;
  //if (argc != 3) {
  //  cout << "Insufficient args" <<  endl;
  //  exit;
  //}
  vector<int> nums{2,3,1,2,4,3};
  cout << "Minimum sub array length is: " << S.minSubArrayLen(7, nums) << endl;
  return 0;
}

