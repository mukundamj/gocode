#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  //Following method uses dynamic programming apprach
  int maxSubArray(vector<int>& nums) {
    int * dp;
    dp  = new int[nums.size()];
    dp[0] = nums[0];
    int max = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = nums[i] + (dp[i - 1] >= 0 ? dp[i - 1] : 0);
      max = max > dp[i] ? max : dp[i];
    }   
    return max;
  }
};

int main() {
  Solution S;
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << S.maxSubArray(nums) << endl;
  return 0;
}

