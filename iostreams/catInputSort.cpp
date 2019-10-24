//Execute the binary of this file as: cat nums.txt | ./binary
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, const char * argv[]) {
 vector<int> nums;
 string input;
 while (getline(std::cin, input)) {
   nums.push_back(stoi(input));
 }
 sort(nums.begin(), nums.end());
 cout << endl;
 for (auto n : nums) {
     printf("%d, ", n);
   }
 cout << endl;
 return 0;
}
