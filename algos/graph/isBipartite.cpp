#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isBipartite(const vector<vector<int>>& graph);
  private:
    bool mark_bins_dfs(const int node, const vector<vector<int>>& graph, vector<char> & bin_of_nodes, vector<bool>& visited);
};

bool Solution::isBipartite(const vector<vector<int>>& graph) {
  int nodes = graph.size();
  vector<char> bin_of_nodes(nodes, 'u');
  vector<bool> visited(nodes, false);

  for (int i = 0; i < nodes; i++) {
    if (!mark_bins_dfs(i, graph, bin_of_nodes, visited)) return false;
  }

  return true;
}

bool Solution::mark_bins_dfs(const int node, const vector<vector<int>>& graph, vector<char> & bin_of_nodes, vector<bool>& visited) {
  if (visited[node]) return true;
  if (bin_of_nodes[node] == 'u') {
    bin_of_nodes[node] = 'a';
  }
  char alt_bin;
  alt_bin = bin_of_nodes[node] == 'a' ? 'b' : 'a';

  for (int n : graph[node]) {
    if (bin_of_nodes[n] == 'u') bin_of_nodes[n] = alt_bin;
    else if (bin_of_nodes[n] == alt_bin) continue;
    else return false;
  }
  visited[node] = true;

  for (int n : graph[node]) {
    if(!mark_bins_dfs(n, graph, bin_of_nodes, visited)) {
      return false;
    }
  }
  return true;
}

int main(int argc, const char* argv[]) {
  Solution S;
  vector<vector<int>> graph = {
    {1, 2, 3},
    {0, 2},
    {0, 1, 3},
    {0, 2},
  };
  vector<vector<int>> graph2 = {
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2},
  };
 
  printf("Is graph bipartite: %d\n", S.isBipartite(graph));
  printf("Is graph2 bipartite: %d\n", S.isBipartite(graph2));
  return 0;
}
