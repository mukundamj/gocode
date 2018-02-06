#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct segmentTreeNode {
  int start, end, sum;
  segmentTreeNode* left;
  segmentTreeNode* right;
  segmentTreeNode (int s, int e) : start(s), end(e), sum(0), left(NULL), right(NULL) {}
};

class NumArray {
  segmentTreeNode* root;
  void updateTree(int, int, segmentTreeNode*);
  int sumRangeQuery(int, int, segmentTreeNode*);
  segmentTreeNode* buildTree(vector<int>&, int, int);
  public:
    NumArray(vector<int> nums);
    void update(int, int);
    int sumRange(int, int);
};

void NumArray::NumArray(vector<int> nums) {
  int n = nums.size();
  root = buildTree(nums, 0, n - 1);
}

void NumArray::update(int index, int val) {
  updateTree(index, val, root);
}

int NumArray::sumRangeQuery(int start, int end) {
  return sumRangeQuery(start, end, root);
}

segmentTreeNode* NumArray::buildTree(vector<int>& nums, int s, int e) {
  segmentTreeNode* node = new segmentTreeNode(s, e);
  if (s == e) {
    node->sum = nums[s];
    return node;
  }
  m = s + (e - s)/2; //To avoid overflow error (s + e)/2 is written as s + (e - s)/2
  node->left = buildTree(nums, s, m);
  node->right = buildTree(nums, m + 1, e);
  node->sum = node->left->sum + node->right->sum;
  return node;
}

void NumArray::updateTree(int index, int val, segmentTreeNode* root) {

}

int NumArray::sumRangeQuery(int start, int end, segmentTreeNode* root) {

}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums = {6, 4, 1, 8, 7, 5, 2, 9};
  vector<int> result = S.countSmaller(nums);
  for (int i : result) printf("%d ",i); 
  cout << endl;
  return 0;
}

