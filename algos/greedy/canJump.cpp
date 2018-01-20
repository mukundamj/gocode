#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canJump(vector<int>);
};

bool Solution::canJump(vector<int> nums) {
  int len = nums.size();
  int i = 0;
  for (int reach = 0; i < len && i <= reach; i++) {
    reach = max(i + nums[i], reach);
  }
  return i == len;
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums = {2, 3, 1, 1, 4};
  vector<int> nums2 = {3, 2, 1, 0, 4};
  cout << "Can jump for nums : " << S.canJump(nums) << endl;
  cout << "Can jump for nums2 : " << S.canJump(nums2) << endl;
  return 0;
}

