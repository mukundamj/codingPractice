#pragma once
#include <vector>
#include <string>

namespace BackTracking {
    bool exist(std::vector<std::vector<char>>& board, const std::string& word);
    bool exist(std::vector<std::vector<char>>& board, const char* pc, const int row, const int col);
}
