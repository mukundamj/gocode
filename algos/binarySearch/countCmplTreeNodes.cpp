#include <iostream>
#include <vector>
#include <math.h>

//The algorithm to this problem is not mine but borrowed
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int countNodes(TreeNode* );
};

int Solution::countNodes(TreeNode* root) {
  if (!root) return 0;
  int leftHeight = 0, rightHeight = 0;
  TreeNode* leftNode = root, * rightNode = root;
  while (leftNode) { leftHeight++; leftNode = leftNode->left; }
  while (rightNode) { rightHeight++; rightNode = rightNode->right; }
  if (leftHeight == rightHeight) {
    return pow(2, leftHeight) - 1;
  } 
  else {
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
}
 

int main(int argc, const char* argv[]) {
  Solution S;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  cout << "Number of nodes = " << S.countNodes(root) << endl;
  return 0;
}
