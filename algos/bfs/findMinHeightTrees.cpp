#include <iostream>
#include <vector> 
#include <unordered_set> 

using namespace std;

class Solution {
  public:
    vector<int> findMinHeightTrees(int, vector<pair<int, int>>&); 
};

struct Node {
  unordered_set<int> neighbor;
  bool isLeaf() const { return neighbor.size() == 1; }
};

/*
  For a undirected graph with tree characteristics, we can choose any node as 
  the root. The result graph is then a rooted tree. Among all possible rooted
  trees, those with minimum height are called minimum height trees (MHTs). 
  Given such a graph, write a function to find all the MHTs and return a list 
  of their root labels.
*/
vector<int> Solution::findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
  vector<int> leafNodesBeforeGraphMutation;
  vector<int> leafNodesAfterGraphMutation;
 
  if (n == 1) {
    leafNodesBeforeGraphMutation.push_back(0);
    return leafNodesBeforeGraphMutation;
  }

  if (n == 2) {
    leafNodesBeforeGraphMutation.push_back(0);
    leafNodesBeforeGraphMutation.push_back(1);
    return leafNodesBeforeGraphMutation;
  }

  //make graph
  vector<Node> nodes(n);
  for (auto e : edges) {
    nodes[e.first].neighbor.insert(e.second); 
    nodes[e.second].neighbor.insert(e.first); 
  }

  //find all the leaf nodes
  for (int i = 0; i < n; i++) {
    if (nodes[i].isLeaf()) leafNodesBeforeGraphMutation.push_back(i); 
  }

  //remove leaf nodes until the root/roots is/are found
  while (1) {
    for (int leaf : leafNodesBeforeGraphMutation) {
      cout << "Processing leaf node " << leaf << endl;
      for (auto neighbor : nodes[leaf].neighbor) {
        cout << "Deleting leaf node which is neighbor of " << neighbor << endl;
        nodes[neighbor].neighbor.erase(leaf);
        if (nodes[neighbor].isLeaf()) leafNodesAfterGraphMutation.push_back(neighbor);
      }
    }
    if (leafNodesAfterGraphMutation.empty()) return leafNodesBeforeGraphMutation;
    leafNodesBeforeGraphMutation.clear();
    leafNodesBeforeGraphMutation = leafNodesAfterGraphMutation;
    leafNodesAfterGraphMutation.clear(); 
  }
}

int main(int argc, const char* argv[]) {
  Solution S;
  int n = 6;
  vector<pair<int,int>> edges;
  edges.push_back(pair<int, int> (0, 3)); 
  edges.push_back(pair<int, int> (1, 3)); 
  edges.push_back(pair<int, int> (2, 3)); 
  edges.push_back(pair<int, int> (4, 3)); 
  edges.push_back(pair<int, int> (5, 4)); 
  vector<int> roots = S.findMinHeightTrees(n, edges);
  for (auto i : roots) cout << i << ", ";
  cout << endl;
  return 0;
}


