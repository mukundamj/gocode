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
    //Given a binary tree, return all root-to-leaf paths
    vector<string> binaryTreePaths(TreeNode*);
    void binaryTreePaths(TreeNode*, string, vector<string> &);
};

vector<string> Solution::binaryTreePaths(TreeNode* root) {
  vector<string> rootToLeafPaths;
  string path;
  binaryTreePaths(root, path, rootToLeafPaths);
  return rootToLeafPaths;
}

void Solution::binaryTreePaths(TreeNode* root, string path, vector<string>& rootToLeafPaths) {
  if (root == NULL) return;
  path = path + "->" + to_string(root->val);
  if (root->left == NULL && root->right == NULL) {
    rootToLeafPaths.push_back(path.substr(2));
    return;
  }
  if (root->left != NULL) {
    binaryTreePaths(root->left, path, rootToLeafPaths);
  }
  if (root->right != NULL) {
    binaryTreePaths(root->right, path, rootToLeafPaths);
  }
  return;
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
  vector<string> rootToLeafPaths = S.binaryTreePaths(s);
  for (int i = 0; i < rootToLeafPaths.size(); i++) {
    cout << rootToLeafPaths[i] << ", "; 
  } 
  cout << endl;
  return 0;
}

