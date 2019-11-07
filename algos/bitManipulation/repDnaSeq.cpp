#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string);
};

/* Using hash approach. This method consumes more memroy */
/*
vector<string> Solution::findRepeatedDnaSequences(string s) {
  unordered_map<string, int> dnaSeq;
  vector<string> result;
  if (s.size() < 10) return result;
  for (int i = 0; i < s.size() - 9; i++) {
    string subStr = s.substr(i, 10);
    cout << "Processing the string : " << subStr << endl;
    if (dnaSeq.end() == dnaSeq.find(subStr)) dnaSeq[subStr] = 1;
    else if (dnaSeq[subStr] == 1) {
      result.push_back(subStr);
      dnaSeq[subStr]++;
    }
    else dnaSeq[subStr]++;
  }
  return result;
}

The below code uses the same algorithm as above, buy has lesser number of code lines.
This code has not been tested

vector<string> Solution::findRepeatedDnaSequences(string s) {
  unordered_map<string, int> dnaSeq;
  vector<string> result;
  for (int i = 0; i + 9 < s.size(); i++) {
    string subStr = s.substr(i, 10);
    if (dnaSeq[subStr]++ == 1) {
      result.push_back(subStr);
    }
  }
  return result;
}

*/

/* 
  This approach is borrowed from LeetCode solution.
  Using bit manipulation approach. This consumes less memory.
  There are only 4 characters; A, C, G and T. The binary representation 
  of A, C, G and T are as below
  A is encoded as 01000001 (0X41)
  C is encoded as 01000101 (0x43)
  G is encoded as 01000111 (0x47)
  T is encoded as 01010100 (0x54)
  Since last 3 digits are different for the 4 characters we can use LSB 
  3 characters for encoding. Each sequence consists of 10 characters so
  an entire sequence can be encoded in 10x3 = 30 bits, which can fit into
  a 32 bit integer. This encoded int value is used in unordered_map<int, int>. 
*/

vector<string> Solution::findRepeatedDnaSequences(string s) {
  unordered_map<int, int> dnaSeqMap;
  vector<string> result;
  int ss = s.size(), dnaSeq = 0, i = 0;
  if (ss < 10) return result;
  while (i < 9) dnaSeq = ((dnaSeq << 3) | (s[i++] & 7));
  while (i < ss) {
    string subStr = s.substr(i - 9, 10);
    if (dnaSeqMap[dnaSeq = dnaSeq << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1) 
      result.push_back(subStr);
  }
  return result;
}

int main(int argc, const char * argv[]) {
  Solution S;
  //string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  string s = "AAAAAAAAAAAAAAA";
  vector<string> result = S.findRepeatedDnaSequences(s);
  cout << "Repeated DNA sequences are" << endl;
  for (auto s : result) cout << s << " ";
  cout << endl;
  return 0;
}

