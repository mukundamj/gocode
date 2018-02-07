#include <iostream>
#include <vector>

using namespace std;

struct segmentTreeNode {
  int start, end, sum;
  segmentTreeNode* left;
  segmentTreeNode* right;
  segmentTreeNode (int s, int e) : start(s), end(e), sum(0), left(NULL), right(NULL) {}
};

class NumArray {
  segmentTreeNode* root;
  int updateTree(int, int, segmentTreeNode*);
  int sumRangeQuery(int, int, segmentTreeNode*);
  segmentTreeNode* buildTree(vector<int>&, int, int);
  public:
    NumArray(vector<int>& nums);
    void update(int, int);
    int sumRange(int, int);
};

NumArray::NumArray(vector<int>& nums) {
  int n = nums.size();
  root = buildTree(nums, 0, n - 1);
}

void NumArray::update(int index, int val) {
  updateTree(index, val, root);
}

int NumArray::sumRange(int start, int end) {
  return sumRangeQuery(start, end, root);
}

segmentTreeNode* NumArray::buildTree(vector<int>& nums, int s, int e) {
  if (s > e) return NULL;
  segmentTreeNode* node = new segmentTreeNode(s, e);
  if (s == e) {
    node->sum = nums[s];
    return node;
  }
  int m = s + (e - s)/2; //To avoid overflow error (s + e)/2 is written as s + (e - s)/2
  node->left = buildTree(nums, s, m);
  node->right = buildTree(nums, m + 1, e);
  node->sum = node->left->sum + node->right->sum;
  return node;
}

int NumArray::updateTree(int index, int val, segmentTreeNode* root) {
  if (index < root->start || index > root->end) return root->sum;
  if (root->start == root->end) {
    if (root->start == index) return root->sum = val;
    return root->sum;
  }
  root->sum = updateTree(index, val, root->left) + updateTree(index, val, root->right);
  return root->sum; 
}

int NumArray::sumRangeQuery(int s, int e, segmentTreeNode* root) {
  if (!root) return 0;
  if (root->start == s && root->end == e) return root->sum;
  int mid = root->start + (root->end - root->start)/2;
  if (mid < s) return sumRangeQuery(s, e, root->right);
  if (mid >= e) return sumRangeQuery(s, e, root->left);
  return sumRangeQuery(s, mid, root->left) + sumRangeQuery(mid + 1, e, root->right);
}

int main(int argc, const char * argv[]) {
 vector<int> nums = {1, 3, 5, 7, 9, 11};
  NumArray N(nums);
  printf("The input array is: ");
  for (int i : nums) cout << i << " ";
  cout << endl;
  printf("Sum of range 0 to 3 is %d\n", N.sumRange(0, 3));
  N.update(2, 10);
  printf("Sum of range 0 to 3 after update is %d\n", N.sumRange(0, 3));
  return 0;
}

