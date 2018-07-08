#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int K, vector<int> &A) {
 unordered_map<int, int> a_map;
 int64_t num_of_pairs = 0;
 for (int i : A)
 {
   a_map[i]++;
 }

 for (int i : A)
 {
   int64_t comp = static_cast<int64_t>(K) - static_cast<int64_t>(i);
   //cout << "Comp = " << comp << endl;
   if (comp > 2147483647 || comp < -2147483648) continue;
   else if (a_map[comp])
   {
     //printf("(%d, %d) ", i, static_cast<int>(comp));
     num_of_pairs += a_map[comp];
   }
 }
 return num_of_pairs;
}

int main(int argc, const char* argv[])
{
  vector<int> nums1 = {1, 8, -3, 0, 1, 3, -2, 4, 5};
  printf("Number of pairs for nums1 are %d\n", solution(6, nums1));
  vector<int> nums2 = {2, 2, 2, 2};
  printf("Number of pairs for nums2 are %d\n", solution(4, nums2));
  vector<int> nums3 = {1};
  printf("Number of pairs for nums3 with k = 2 are %d\n", solution(2, nums3));
  printf("Number of pairs for nums3 with k = 3 are %d\n", solution(3, nums3));
  
  vector<int> nums4 = {2147483647};
  printf("Number of pairs for nums4 with k = -2 are %d\n", solution(-2, nums4));
  vector<int> nums5 = {-2147483648};
  printf("Number of pairs for nums5 with k = 1 are %d\n", solution(1, nums5));

  vector<int> nums6 = {1073741823, 1073741823, 1073741823, 1073741823};
  printf("Number of pairs for nums6 with k = 2147483646 are %d\n", solution(2147483646, nums6));

  vector<int> nums6b = {1073741824, 1073741824, 1073741824, 1073741824};
  printf("Number of pairs for nums6b with k = 2147483647 are %d\n", solution(2147483647, nums6b));

  vector<int> nums7 = {-1073741824, -1073741824, -1073741824, -1073741824};
  printf("Number of pairs for nums7 with k = -2147483648 are %d\n", solution(-2147483648, nums7));

  vector<int> nums8;
  for (int i = 0; i < 40000; i++)
  {
    nums8.push_back(1073741823);
  }
  printf("Number of pairs for nums8 with k = 2147483646 are %d\n", solution(2147483646, nums8));

  vector<int> nums9;
  for (int i = 0; i < 40000; i++)
  {
    nums9.push_back(-1073741824);
  }
  printf("Number of pairs for nums9 with k = -2147483648 are %d\n", solution(-2147483648, nums9));

  vector<int> nums10 = {1, 2, 1, 2};
  printf("Number of pairs for nums10 with k = 3 are %d\n", solution(3, nums10));

  vector<int> nums11 = {-1, 2, -1, 2};
  printf("Number of pairs for nums11 with k = 3 are %d\n", solution(1, nums11));



  return 0;
}
