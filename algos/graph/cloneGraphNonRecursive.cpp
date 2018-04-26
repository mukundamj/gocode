#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode
{
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

//This code does the same job as the other clone graph code but uses iterative
//approach instead of recursive approach
class Solution
{
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    void print_graph(UndirectedGraphNode *node);
};

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
 //TODO
}

void Solution::print_graph(UndirectedGraphNode *node)
{
 //TODO
}

int main(int argc, const char *argv[])
{
  Solution S;
  UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
  UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
  UndirectedGraphNode *node3 = new UndirectedGraphNode(3);
  UndirectedGraphNode *node4 = new UndirectedGraphNode(4);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node4);
  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);
  node3->neighbors.push_back(node2);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node1);
  node4->neighbors.push_back(node3);
  S.print_graph(node1);
  UndirectedGraphNode *cloned_graph = S.cloneGraph(node1);
  S.print_graph(cloned_graph);
  return 0;
}
