//Problem statement: A file containing numbers is piped as input to the executable,
//the executable should store the numbers, sort them and print the sorted output.
//Execute the binary of this file as: cat nums.txt | ./binary
#include <iostream>
#include <vector>
#include <algorithm>

int main (int argc, const char * argv[]) {
 std::vector<int> nums;
 std::string input;
 while (getline(std::cin, input)) {
   nums.push_back(std::stoi(input));
 }
 std::sort(nums.begin(), nums.end());
 std::cout << endl;
 for (auto n : nums) {
     std::cout << n;
 }
 std::cout << endl;
 return 0;
}
