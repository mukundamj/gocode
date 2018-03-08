#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int, vector<int>&); 
};

int Solution::minSubArrayLen(int s, vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int len = INT_MAX, start = 0, end = 0, sum = 0;
  while (end < nums.size() && start <= end) {
    sum += nums[end];
    if (sum < s) {
      end++;
    }
    if (sum > s) {
      len = min(len, (end - start + 1));
      sum -= nums[start++]; 
      sum -= nums[end]; 
    }
    if (sum == s) {
      len = min(len, (end - start + 1));
      sum -= nums[start++]; 
      end++;
    }
  }
  len = (len == INT_MAX) ? 0 : len;
  return len;
}

int main(int argc, const char * argv[]) {
  Solution S;
  //if (argc != 3) {
  //  cout << "Insufficient args" <<  endl;
  //  exit;
  //}
  vector<int> nums{2,3,1,2,4,3};
  cout << "Minimum sub array length is: " << S.minSubArrayLen(7, nums) << endl;
  return 0;
}

