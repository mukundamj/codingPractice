#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>&, int); 
};

bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
  int m = matrix.size();
  if (m == 0) return false;
  int n = matrix[0].size();
  int i = 0, j = n -1;
  while (i < n && j >=0) {
    if (matrix[i][j] == target) return true;
    else if (matrix[i][j] > target) {
      j--;
    }
    else {
      i++;
    }
  }
  return false;
}
 

int main(int argc, const char* argv[]) {
  Solution S;
  vector<vector<int>> matrix(1);
  matrix[0].push_back(1);
  matrix[0].push_back(1);
  //matrix[0].push_back(3);
  //matrix[1].push_back(4);
  //matrix[1].push_back(5);
  //matrix[1].push_back(6);
  //matrix[2].push_back(7);
  //matrix[2].push_back(8);
  //matrix[2].push_back(9);
  cout << "Does the target exist? " << S.searchMatrix(matrix, 1) << endl;
  return 0;
}
