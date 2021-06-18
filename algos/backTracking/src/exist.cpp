#include <iostream>
#include "exist.h" 

namespace BackTracking {

/*
 Time complexity of running the for loop is T_exist1(n) = O(m x n x T_exist2(n)) where m is the
 number of rows, n is the number of columns and T_exist2(n) is the time complexity of the
 recursive exist(...) function.

 From the calculation done below T_exist2(n) = search_word_size, hence the overall time comlexity is
 T(n) = O(m x n x search_word_size)
*/
bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
  if (!word.size()) return true;
  if (!board.size()) return false;

  std::cout << "Searching the word : " << word << std::endl;

  int row = board.size();
  int col = board[0].size();

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (exist(board, &word[0], i, j)) return true;
    }
  }

  return false;
}

/*
 The recursive call is similar to DFS search. The maximum depth of each of the 4 recursive calls
 is equal to (search_word_size - 1), hence T_exist2(n) = O(search_word_size).

 In these kind of code it's not straight forward to calculate the time complexity. To simplify things
 just put a print statement in the appropriate place and determine how many time the print gets executed.
 In this example putting a print statement before the if( recursive calls ) can give an idea of the
 time complexity. 
*/
bool exist(std::vector<std::vector<char>>& board, const char* pc, const int i, const int j) {
  int row = board.size();
  int col = board[0].size();
  
  if ((i < 0) || (j < 0) || (i >= row) || (j >= col) || (board[i][j] == '$') || (*pc != board[i][j])) {
    return false;
  }

  if (*(pc + 1) == '\0') return true;

  char temp = board[i][j];
  board[i][j] = '$';

  std::cout << "row = " << i << ", col = " << j << ", char = " << temp << std::endl;

  if (exist(board, pc + 1, i - 1, j) ||  exist(board, pc + 1, i, j + 1) || exist(board, pc + 1, i + 1, j) || exist(board, pc + 1, i, j - 1)) {
    board[i][j] = temp; 
    return true;
  }

  board[i][j] = temp; 
  return false;
}

}
