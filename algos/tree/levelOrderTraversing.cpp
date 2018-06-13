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
    vector<vector<int>> levelOrder(TreeNode *root);
};


//This function prints a tree in level order without using recusrion. 
vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
  vector<vector<int>> result;
  if (!root) return result;
  vector<TreeNode *> parent_queue, child_queue;
  parent_queue.push_back(root);
  vector<int> level;
  
  while(!parent_queue.empty()) 
  {
    for (auto n : parent_queue)
    {
      if (n) 
      {
        //printf("%d ", n->val);
        level.push_back(n->val);
        child_queue.push_back(n->left);
        child_queue.push_back(n->right);
      }
      //else printf(" ");
    }
    //printf("\n");
    if (!level.empty()) result.push_back(level);
    level.clear();
    parent_queue = child_queue; 
    child_queue.clear(); 
  }

  return result;
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
  S.levelOrder(r);
  return 0;
}
