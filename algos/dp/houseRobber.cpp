#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      nums.push_back(0);
      nums.push_back(0);
      nums[2] = nums[2] + nums[0];
      for (int i = 3; i < nums.size(); i++) {
        nums[i] += (nums[i - 2] > nums[i - 3] ? nums[i - 2] : nums[i - 3]);
      }
      return nums[nums.size() - 1];
    }

};

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums{100, 500, 50, 30, 900, 800, 750, 10};
  cout << S.rob(nums) << endl;
  return 0;
}
