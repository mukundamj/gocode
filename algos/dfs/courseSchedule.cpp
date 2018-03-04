#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//There are a total of n courses you have to take, labeled from 0 to n - 1.
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? 

class Solution {
  public:
    bool canFinish(int, vector<pair<int, int>>&);
    void make_adjacency_list(vector<unordered_set<int>>&, vector<pair<int, int>>&);
    bool dfs_cycle_exists(int, vector<bool>&, vector<bool>&, vector<unordered_set<int>>&);
};

bool Solution::canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<unordered_set<int>> adjacencyList(numCourses);
  vector<bool> visited(numCourses, false), onPath(numCourses, false);
  make_adjacency_list(adjacencyList, prerequisites);
  for (int i = 0; i < numCourses; i++) {
    if (!visited[i] && dfs_cycle_exists(i, visited, onPath, adjacencyList)) {
      return false;
    }
  }
  return true;
}

void Solution::make_adjacency_list(vector<unordered_set<int>>& adjacencyList, vector<pair<int, int>>& prerequisites) {
  for (auto p : prerequisites) {
    cout << "(" << p.first << ", " << p.second << ")" << endl;
    adjacencyList[p.second].insert(p.first); 
  } 
  return;
}

bool Solution::dfs_cycle_exists(int node, vector<bool>& visited, vector<bool>& onPath, vector<unordered_set<int>>& adjacencyList) {
  if (visited[node]) return false;
  visited[node] = onPath[node] = true;
  for (auto n : adjacencyList[node]) {
    if (onPath[n] || dfs_cycle_exists(n, visited, onPath, adjacencyList)) {
      return true;
    }
  }
  return onPath[node] = false;
}

int main(int argc, const char* argv[]) {
  Solution S;
  vector<pair<int, int>> prerequisites;
  prerequisites.push_back(make_pair(1, 2));
  prerequisites.push_back(make_pair(2, 3));
  prerequisites.push_back(make_pair(3, 4));
  prerequisites.push_back(make_pair(3, 5));
  prerequisites.push_back(make_pair(2, 5));
  cout << "Can the courses be completed? " << S.canFinish(6, prerequisites) << endl;
  return 0;
}
