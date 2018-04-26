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

//This program has not been thoroughly tested
class Solution
{
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    void print_graph(UndirectedGraphNode *node, unordered_set<int> &labels_visited);
  private:
    void cloneGraph(UndirectedGraphNode *node, UndirectedGraphNode *&clone_graph_node, 
      unordered_set<int> &labels_visited); 
};

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
  unordered_set<int> labels_visited;
  UndirectedGraphNode *clone_graph_node = new UndirectedGraphNode(node->label); 
  cloneGraph(node, clone_graph_node, labels_visited);
  return clone_graph_node;
}


void Solution::cloneGraph(UndirectedGraphNode *node, 
  UndirectedGraphNode *&clone_graph_node, unordered_set<int> &labels_visited) 
{
  if (labels_visited.find(node->label) != labels_visited.end()) return;
  clone_graph_node->label = node->label;
  for (auto n : node->neighbors)
  {
    clone_graph_node->neighbors.push_back(new UndirectedGraphNode(n->label));
  }
  labels_visited.insert(node->label);

  for (int i = 0; i < node->neighbors.size(); i++)
  {
    cloneGraph(node->neighbors[i], clone_graph_node->neighbors[i], labels_visited); 
  }

  return;
}

void Solution::print_graph(UndirectedGraphNode *node, unordered_set<int> &labels_visited)
{
  if (labels_visited.find(node->label) != labels_visited.end()) return;
  printf("address of node is %p and node label is %d -> ", node, node->label);
  for (auto n : node->neighbors)
  {
    printf("%d ", n->label);
  }
  printf("\n");
  labels_visited.insert(node->label);
  for (auto n : node->neighbors)
  {
    print_graph(n, labels_visited);
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
  unordered_set<int> labels_visited;
  cout << "Size of UndirectedGraphNode is " << sizeof(UndirectedGraphNode) << "\n";
  cout << "Size of UndirectedGraphNode neighbor is " << sizeof(UndirectedGraphNode::neighbors) << "\n";
  cout << "Size of UndirectedGraphNode label is " << sizeof(UndirectedGraphNode::label) << "\n";
  printf("Original graph address is %p\n", node1);
  S.print_graph(node1, labels_visited);
  labels_visited.clear();
  UndirectedGraphNode *cloned_graph = S.cloneGraph(node1);
  printf("Cloned graph address is %p\n", cloned_graph);
  S.print_graph(cloned_graph, labels_visited);
  return 0;
}
