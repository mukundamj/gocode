#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  //Following method uses dynamic programming apprach, the results computed are stroed in the dp array
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

  //Since we don't have to remember all the past results this problem can also be solved without using a dp approach
  int maxSubArrayFast(vector<int>& nums) {
    int sum = 0;
    int max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      sum = sum + nums[i]; 
      max = max > sum ? max : sum;
      sum = sum > 0 ? sum : 0;
    }   
    return max;
  }

};

int main() {
  Solution S;
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << S.maxSubArray(nums) << endl;
  cout << S.maxSubArrayFast(nums) << endl;
  return 0;
}

