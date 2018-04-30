#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
  public:
    bool delete_tree_without_recursion(TreeNode *&root);
    void print_tree(TreeNode *root);
};

bool Solution::delete_tree_without_recursion(TreeNode *&root)
{
  if (!root) return true;
  vector<TreeNode *> queue; 
  queue.push_back(root);
  
  while(!queue.empty()) 
  {
    TreeNode *temp = queue.back();
    queue.pop_back();
    if (temp->left) queue.push_back(temp->left);
    if (temp->right) queue.push_back(temp->right);
    delete temp;
  }

  root = NULL;
  return true;
}

void Solution::print_tree(TreeNode *root)
{
  if (!root) return;
  cout << root->val << endl;  
  print_tree(root->left);
  print_tree(root->right);
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
  cout << "Tree before deleting\n";
  S.print_tree(r);
  if (S.delete_tree_without_recursion(r))
  {
    cout << "Tree was successfully deleted " ;
  }
  cout << "\nTree after deleting\n";
  S.print_tree(r);
  return 0;
}
