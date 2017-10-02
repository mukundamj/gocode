#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      nums.push_back(0);
      nums.push_back(0);
      int end = nums.size() - 1;
      if (end >= 2) {
        nums[end - 2] += nums[end];
        for (int i = end - 3; i >= 0; i--) {
          nums[i] += (nums[i + 2] > nums[i + 3] ? nums[i + 2] : nums[i + 3]);
        } 
      }
      return nums[0] > nums[1] ? nums[0] : nums[1]; 
    }
};

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums{100, 500, 50, 30, 900, 800, 750, 10};
  cout << S.rob(nums) << endl;
  return 0;
}

