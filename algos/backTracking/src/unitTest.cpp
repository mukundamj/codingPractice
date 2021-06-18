#include <iostream> 
#include "exist.h"
#include "gtest/gtest.h"

TEST(BackTracking, simpleBoard)
{
  std::vector<std::vector<char>> board = {
    {'A','B','C','E'}, 
    {'S','F','C','S'}, 
    {'A','D','E','E'}, 
  };

  std::cout << "The board looks as below" << std::endl;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      std::cout << board[i][j] << ", ";
    }
    std::cout << std::endl;
  }

  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "A"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "AB"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "ABC"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "ABCE"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "ABCESCFS"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "ABCESCFSADEE"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "ASA"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "BFD"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "BFDECCESE"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "BCCEESE"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "CC"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, "ABCESEEDASFC"));
  std::cout << "================================================"<< std::endl;
  EXPECT_TRUE(BackTracking::exist(board, ""));
  std::cout << "================================================"<< std::endl;
  EXPECT_FALSE(BackTracking::exist(board, "ABCESEEDASFCS"));
  std::cout << "================================================"<< std::endl;
  EXPECT_FALSE(BackTracking::exist(board, "CSC"));
  std::cout << "================================================"<< std::endl;
  EXPECT_FALSE(BackTracking::exist(board, "CFA"));
  std::cout << "================================================"<< std::endl;
  EXPECT_FALSE(BackTracking::exist(board, "FA"));
  std::cout << "================================================"<< std::endl;
  EXPECT_FALSE(BackTracking::exist(board, "G"));
  std::cout << "================================================"<< std::endl;
}

TEST(BackTracking, emptyBoard)
{
  std::vector<std::vector<char>> board = {{}};

  std::cout << "The board looks as below" << std::endl;
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      std::cout << board[i][j] << ", ";
    }
    std::cout << std::endl;
  }

  EXPECT_FALSE(BackTracking::exist(board, "A"));
  EXPECT_TRUE(BackTracking::exist(board, ""));
}
