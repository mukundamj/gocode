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
    bool isValidBST(TreeNode*);
    bool isValidBST(TreeNode*, TreeNode*&);
};

bool Solution::isValidBST(TreeNode* root) {
  TreeNode* prev = NULL;
  return isValidBST(root, prev);
}

bool Solution::isValidBST(TreeNode* root, TreeNode*& prev) {
  if (!root) return true;
  if (!isValidBST(root->left, prev)) return false; 
  if (prev && prev->val >= root->val) return false;
  prev = root;
  return (isValidBST(root->right, prev)); 
}

int main(int argc, const char* argv[]) {
  Solution S;
  TreeNode* s = new TreeNode(3);
  s->left = new TreeNode(1);
  s->left->left = new TreeNode(0);
  s->left->right = new TreeNode(2);
  s->right = new TreeNode(5);
  s->right->left = new TreeNode(4);
  s->right->right = new TreeNode(6);
  cout << "Is it a valid BST?  " << S.isValidBST(s) << endl;
  return 0;
}

