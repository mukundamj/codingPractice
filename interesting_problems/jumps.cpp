#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> &A) {
 int jumps = 0, pos = 0;
 unordered_set<int> index_map;
 while (pos < A.size() && pos >= 0)
 {
   pos = pos + A[pos];
   if (index_map.find(pos) != index_map.end()) return -1;
   jumps++;
   index_map.insert(pos);
 }
 return jumps;
}

int main(int argc, const char* argv[])
{
  cout << "Size of int " << sizeof(int) << endl;
  vector<int> nums = {2, 3, -1, 1, 3}; //Ans = 4
  vector<int> nums2 = {1, 1, -1, 1}; //Ans = -1
  vector<int> nums3 = {-1, 1, -1, 1}; //Ans = 1
  vector<int> nums4 = {1, 1, 1, 1, -3, 1}; //Ans = -1
  vector<int> nums5 = {0}; //Ans = -1
  vector<int> nums6 = {0, 1}; //Ans = -1
  vector<int> nums7 = {1, 0}; //Ans = -1
  vector<int> nums8 = {1, 1000000}; //Ans = 2
  vector<int> nums9 = {-1000000, 1000000}; //Ans = 1
  printf("Number of jumps for nums %d\n", solution(nums));
  printf("Number of jumps for nums2 %d\n", solution(nums2));
  printf("Number of jumps for nums3 %d\n", solution(nums3));
  printf("Number of jumps for nums4 %d\n", solution(nums4));
  printf("Number of jumps for nums5 %d\n", solution(nums5));
  printf("Number of jumps for nums6 %d\n", solution(nums6));
  printf("Number of jumps for nums7 %d\n", solution(nums7));
  printf("Number of jumps for nums8 %d\n", solution(nums8));
  printf("Number of jumps for nums9 %d\n", solution(nums9));
  
  vector<int> nums10;
  for (int i = 0; i < 100000; i++)
  {
    nums10.push_back(1); 
  }
  nums10[99999] = 1000000; //Ans = 100000
  printf("Number of jumps for nums10 %d\n", solution(nums10));
  vector<int> nums11 = nums10;
  nums11[99999] = -1000000; //Ans = 100000
  printf("Number of jumps for nums11 %d\n", solution(nums11));
  vector<int> nums12 = nums10;
  nums12[99999] = -99999; //Ans = -1
  printf("Number of jumps for nums12 %d\n", solution(nums12));

  vector<int> nums13 = {7, 5, 3, 1, -4, -2, -4, -6}; //Ans = -1
  printf("Number of jumps for nums13 %d\n", solution(nums13));
  vector<int> nums14 = {7, 5, 3, 1, 4, -2, -4, -6}; //Ans = 8
  printf("Number of jumps for nums14 %d\n", solution(nums14));

  vector<int> nums15 = {-1000000}; //Ans = 1
  printf("Number of jumps for nums15 %d\n", solution(nums15));

  return 0;
}
