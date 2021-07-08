#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> topKFrequent(vector<string>& words, int k);
};

struct comparePairs {
  bool operator() (const pair<string, int>& a, const pair<string, int>& b)
  {
    if (a.second > b.second) return true; 
    else if (a.second == b.second) {
      return (a.first < b.first);
    }
    else return false;
  }
};

vector<string> Solution::topKFrequent(vector<string>& words, int k) {
  map<string, int> words_count_map;
  vector<pair<string, int>> words_count_vec; 
  vector<string> res;

  //Time complexity of this for loop in nlog(n)
  for (auto s : words) {
    words_count_map[s]++;
  }

  for (auto p : words_count_map) {
    words_count_vec.emplace_back(p.first, p.second);
  }

  //Sorting the vector with custom comparator class
  //The time required to run when compare class is used is high compared to
  //using lambda function
  //Time complexity of this sorting process in nlog(n)
  //sort (words_count_vec.begin(), words_count_vec.end(), comparePairs());

  //Sorting the vector using custom comparator lambda function
  //Time complexity of this sorting process in nlog(n)
  sort
  (
    words_count_vec.begin(), words_count_vec.end(), 
    [](const pair<string, int>& a, const pair<string, int>& b)
    {
      if (a.second > b.second) return true; 
      else if (a.second == b.second) {
        return (a.first < b.first);
      }
      else return false;
    }
  );

  for (int i = 0; i < k; i++) {
    res.push_back(words_count_vec[i].first); 
  }

  return res;

  ////As an alternate approach bucket sort can be used which has lesser time
  ////complexity than nlong(n). This solution was found in leet code

  //vector<vector<string>> bucket(words.size());
  //for (auto it : words_count_map) {
  //  //since the map STL sorts its values by keys when the bucket is inserted
  //  //with values it will be in sorted order
  //  bucket[it.second].push_back(it.first);
  //}
  //cout << "print done" << endl;
  //
  //for (int i = (int)bucket.size() - 1; k > 0 && i >= 0; i--) {
  //  if (bucket[i].empty())
  //    continue;
  //  int n = min(k, (int)bucket[i].size());
  //  //since the bucket has already sorted keys when there is no need to sort
  //  //among words having same frequency 
  //  res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + n);
  //  k -= n;
  //}
  //
  //return res;
  
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<string> list_of_strings = {"the", "day", "is", "sunny", "the", "the",
     "the", "sunny", "is", "is"
  };
  vector<string> result = S.topKFrequent(list_of_strings, 4);
  for (auto s : result) {
    cout << s << '\n';
  }
  return 0;
}
