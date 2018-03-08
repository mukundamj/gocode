#include <iostream>
#include <vector>
#include "sha256.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q); 
  private:
    string _merkle(TreeNode *);
};

//Simple recursive approach
/*
bool Solution::isSameTree(TreeNode* s, TreeNode* t) {
  if (!s && !t) return true;
  if (s && t) {
    return ((s->val == t->val) && (isSameTree(s->left, t->left)) && (isSameTree(s->right, t->right)));
  }
  return false;
}
*/

//Using Merkle tree approach
bool Solution::isSameTree(TreeNode* s, TreeNode* t) {
  if (!s && !t) return true;
  if (s && t) {
    //cout << "hash of s " << _merkle(s) << endl;
    //cout << "hash of t " << _merkle(t) << endl;
    return (_merkle(s) == _merkle(t)); 
  }
  return false;
}

string Solution::_merkle(TreeNode * n) {
  if (!n) return string("#"); 
  SHA256 sha256;
  return sha256(_merkle(n->left) + to_string(n->val) + _merkle(n->right));
}

int main(int argc, const char * argv[]) {
  Solution S;
  TreeNode *s = new TreeNode(3);
  s->left = new TreeNode(4);
  s->left->left = new TreeNode(1);
  s->left->right = new TreeNode(2);
  s->left->right->left = new TreeNode(0);
  s->right = new TreeNode(5);
  TreeNode *t = new TreeNode(3);
  t->left = new TreeNode(4);
  t->left->left = new TreeNode(1);
  t->left->right = new TreeNode(2);
  t->left->right->left = new TreeNode(0);
  t->right = new TreeNode(5);

  cout << "Are both trees same? " << S.isSameTree(s, t);
  cout << endl;
  return 0;
}

