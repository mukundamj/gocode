#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findPeakElement(vector<int> &nums);
};

//A peak element is an element that is greater than its neighbors.
//The array may contain multiple peaks, in that case return the index to any
//one of the peaks is fine.
//Input: nums = [1, 2, 3, 1]
//Output: 2 because 2 is the index of 3
//The geeks for geeks has a slightly different definition, it says peak
//number as the which is not lesser than its neighbors. It also has a
//O(lon(n)) algorithm
int Solution::findPeakElement(vector<int> &nums)
{
  int peak_index = 0;
  for(int i = 1; i < nums.size() - 1; i++)
  {
    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
    {
      peak_index = i; 
      break;
    }
  }
  
  return peak_index;
}

int main (int argc, const char *argv[])
{
  Solution S;
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  printf("Peak element index is %d\n", S.findPeakElement(nums));
  return 0;
}
