#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>&);
};

//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//Your algorithm should run in O(n) complexity. 

int Solution::longestConsecutive(vector<int>& nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  int longest = 0;
  for (unordered_set<int>::iterator it = s.begin(); it != s.end(); it++) {
    int j = *it - 1, k = *it + 1;
    while (s.find(j) != s.end()) s.erase(s.find(j--));
    while (s.find(k) != s.end()) s.erase(s.find(k++));
    longest = max(longest, k - j - 1);
  }
  return longest;
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  printf("Longest number of consecutive integers are: %d\n", S.longestConsecutive(nums));
  return 0;
}

