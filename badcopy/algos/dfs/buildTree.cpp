#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    //Given preorder and inorder traversal of a tree, construct the binary tree.
    TreeNode* buildTree(vector<int>&, vector<int>&);
};

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
  int i = 0, j = 0;
  TreeNode* root = new TreeNode(0xefffffff); //can also use INT_MAX as value. The value is set to some high value so that it doesn't inadvertantly match any if conditions inside while loop
  TreeNode* tbdRoot = NULL, * returnRoot = root;
  stack<TreeNode*> preorderStack;
  preorderStack.push(root);
  while (j < inorder.size()) {  //can also use the condition i < preorder.size()
    cout << inorder[j] << " ";
    if (preorderStack.top()->val == inorder[j]) {
      tbdRoot = preorderStack.top();
      preorderStack.pop();
      j++;
    }
    else if (tbdRoot) {
      root = new TreeNode(preorder[i++]);
      tbdRoot->right = root;
      tbdRoot = NULL;
      preorderStack.push(root);
    }
    else {
      root = new TreeNode(preorder[i++]);
      preorderStack.top()->left = root;
      preorderStack.push(root);
    }
  }
  root = returnRoot->left;
  delete returnRoot;
  return root;
}

void printTree(TreeNode* tree) {
  if (tree == NULL) return;
  printTree(tree->left);
  cout << tree->val << " ";
  printTree(tree->right);
  return;
}

int main(int argc, const char* argv[]) {
  Solution S;
  vector<int> preorder = {3, 1, 0, 2, 5, 4, 6}, inorder = {0, 1, 2, 3, 4, 5, 6};
  TreeNode* tree = S.buildTree(preorder, inorder);
  cout << "\nReconstructed tree is\n";
  printTree(tree);
  cout << "\n";
  return 0;
}
