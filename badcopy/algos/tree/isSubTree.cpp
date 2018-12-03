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
    bool isSubtree(TreeNode *, TreeNode *); 
  private:
    vector<TreeNode *> nodes;
    TreeNode *target;
    int _findDepthOfTree(TreeNode *, int);
    bool _isMatching(TreeNode *, TreeNode *);
};

//Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and 
//node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's 
//descendants. The tree s could also be considered as a subtree of itself. 
bool Solution::isSubtree(TreeNode* s, TreeNode* t) {
  if (s && t) {
    target = t;
    int d = _findDepthOfTree(t, -1);
    cout << "Depth of tree t is " << d << endl;
    _findDepthOfTree(s, d);
    cout << "vector<TreeNode *> is populated"<< endl;
    for (TreeNode *n : nodes) {
      cout << "Checking if _isMatching for node " << n->val << endl;
      if (_isMatching(n, t)) return true;
    }
  }
  return false;
}

int Solution::_findDepthOfTree(TreeNode *s, int d) {
  if (!s) return -1;
  int depth = max(_findDepthOfTree(s->left, d), _findDepthOfTree(s->right, d)) + 1; 
  if ((d == depth) && (target->val == s->val)) {
    nodes.push_back(s); 
    cout << "Value = " << s->val << " Depth = " << d << endl;
  }
  return depth;
}

bool Solution::_isMatching(TreeNode *n, TreeNode *t) {
  if (!n && !t) return true;
  if (n && t) {
    return (n->val == t-> val && _isMatching(n->left, t->left) && _isMatching(n->right, t->right));
  }
  return false; 
}


int main(int argc, const char * argv[]) {
  Solution S;
  TreeNode *s = new TreeNode(3);
  s->left = new TreeNode(4);
  s->left->left = new TreeNode(1);
  s->left->right = new TreeNode(2);
  s->left->right->left = new TreeNode(0);
  s->right = new TreeNode(5);
  TreeNode *t = new TreeNode(4);
  t->left = new TreeNode(1);
  t->right = new TreeNode(2);
  cout << "Is is a subtree? " << S.isSubtree(s, t);
  cout << endl;
  return 0;
}

