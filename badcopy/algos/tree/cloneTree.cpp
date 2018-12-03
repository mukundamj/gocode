#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution
{
  public:
    TreeNode *clone_tree(TreeNode *root);
    void print_tree(TreeNode *root); 
};

//Assuming that none of the node values are repeated. Cloning of tree is done 
//using iterative approach
TreeNode * Solution::clone_tree(TreeNode *root)
{
  if (!root) return NULL;
  vector<TreeNode *> queue;
  queue.push_back(root);
  unordered_map<int, TreeNode*> map;
  map[root->val] = new TreeNode(root->val);
 
  while (!queue.empty())
  {
    auto r = queue.back();
    queue.pop_back();
    TreeNode *clone_root = map[r->val];
    if (r->left)
    {
      TreeNode *left = new TreeNode(r->left->val);
      queue.push_back(r->left);
      clone_root->left = left;
      map[left->val] = left;
    }
    if (r->right)
    {
      TreeNode *right = new TreeNode(r->right->val);
      queue.push_back(r->right);
      clone_root->right = right;
      map[right->val] = right;
    }
  } 
  return map[root->val];
}

//Level order traversing
void Solution::print_tree(TreeNode *root)
{
  vector<TreeNode *> parent_queue;
  vector<TreeNode *> child_queue;
  parent_queue.push_back(root);

  while (!parent_queue.empty())
  {
    for (auto r : parent_queue)
    {
      printf(" %d", r->val);
      if (r->left) child_queue.push_back(r->left);
      if (r->right) child_queue.push_back(r->right);
    }
    parent_queue = child_queue;
    child_queue.clear();
    printf("\n");
  }
  return;
}

int main(int argc, const char *argv[])
{
  Solution S;
  TreeNode *r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  r->left->left = new TreeNode(4);
  r->left->right = new TreeNode(5);
  r->right->left = new TreeNode(6);
  r->right->right = new TreeNode(7);
  TreeNode *cloned_tree_root = S.clone_tree(r);
  printf("Original tree is as below\n");
  S.print_tree(r);
  printf("Clone tree is as below\n");
  S.print_tree(cloned_tree_root);
  return 0;
}
