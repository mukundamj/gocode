#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode
{
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    void print_graph(UndirectedGraphNode *node);
};

//The logic I implemedted before used a recursive approach but the below
//approach uses iteration.
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
  unordered_map<int, UndirectedGraphNode*> map_cloned_nodes;
  map_cloned_nodes[node->label] = new UndirectedGraphNode(node->label);
  vector<UndirectedGraphNode *> queue_of_nodes;
  queue_of_nodes.push_back(node);
  
  while (!queue_of_nodes.empty())
  {
    auto node = queue_of_nodes.back();
    auto clone_node = map_cloned_nodes[node->label];
    queue_of_nodes.pop_back();
    for (auto n : node->neighbors)
    {
      if (map_cloned_nodes[n->label] == NULL)
      {
        map_cloned_nodes[n->label] = new UndirectedGraphNode(n->label);
        queue_of_nodes.push_back(n);
      }
      clone_node->neighbors.push_back(map_cloned_nodes[n->label]);
    }
  }
  
  return map_cloned_nodes[node->label];
}

void Solution::print_graph(UndirectedGraphNode *node)
{
  vector<UndirectedGraphNode *> queue_of_nodes;
  unordered_set<int> visited;
  queue_of_nodes.push_back(node);
  
  while (!queue_of_nodes.empty())
  {
    auto node = queue_of_nodes.back();
    queue_of_nodes.pop_back();
    if (visited.find(node->label) != visited.end()) continue;
    printf("Address %p. Label %d -> ", node, node->label);
    for (auto n : node->neighbors)
    {
      printf(" %d", n->label);
      if (visited.find(n->label) == visited.end())
      {
        queue_of_nodes.push_back(n);
      }

    }
    visited.insert(node->label);
    printf("\n");
  }

  return;
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
  cout << "Cloned graph\n";
  S.print_graph(cloned_graph);
  return 0;
}
