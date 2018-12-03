#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode*, TreeNode*, TreeNode*); 
};

//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes 
//v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a 
//descendant of itself).” 

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root == p || root == q) return root;
  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  return !left ? right : (!right ? left : root); 
}

int main(int argc, const char* argv[]) {
  Solution S;
  TreeNode* s = new TreeNode(3);
  s->left = new TreeNode(4);
  TreeNode* p = s->left->left = new TreeNode(1);
  TreeNode* q = s->left->right = new TreeNode(2);
  s->left->right->left = new TreeNode(0);
  s->right = new TreeNode(5);
  TreeNode* lca = S.lowestCommonAncestor(s, p, q);
  cout << "LCA is: " << lca->val << endl;
  return 0;
}

