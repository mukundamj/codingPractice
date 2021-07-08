#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string largestNumber(vector<int>&);
};

string Solution::largestNumber(vector<int>& nums) {
  vector<string> result;
  string ret;
  if (nums.empty()) return ret;
  for (auto n : nums) 
    result.push_back(to_string(n));
  sort(result.begin(), result.end(), [] (string &s1, string &s2) {return s1 + s2 > s2 + s1;});
  for (auto s : result)
    ret += s; 
  if (ret[0] == '0' && ret.length() > 1)
    ret.erase(0, ret.length() - 1);
  return ret;
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums = {3, 30, 34, 5, 9};
  string largestNum = S.largestNumber(nums);
  printf("The largest number is %s\n", largestNum.c_str());
  return 0;
}

