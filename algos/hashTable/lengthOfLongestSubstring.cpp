#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string );
};
//Given a string, find the length of the longest substring without repeating characters.
int Solution::lengthOfLongestSubstring(string s) {
  if (s.size() == 0) return 0;
  unordered_set<char> sMap;
  int max = 1, begin = 0, end = 1;
  sMap.insert(s[begin]);
  while (end < s.size()) {
    if (sMap.find(s[end]) == sMap.end()) {
      sMap.insert(s[end++]);
    }  
    else {
      max = max >= (end - begin) ? max : (end - begin);
      while (s[begin] != s[end]) {
        sMap.erase(s[begin]);
        begin++; 
      }
      begin++;
      end++;
    }
  }
  max = max >= (end - begin) ? max : (end - begin);
  return max;
}

/*
My easier solution
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;
        int b = 0, e = 1, longest = 0;
        vector<int> map_s(255, 0);
        map_s[s[b]]++;
        while (e < s.size()){
            map_s[s[e]]++;
            if (map_s[s[e]] > 1){
                longest = max(longest, e - b);
                while (map_s[s[b]] == 1){
                    map_s[s[b]]--;
                    b++;
                }
                map_s[s[b]]--;
                b++;
            }
            e++;
        }
        longest = max(longest, e - b);
        return longest;
    }
*/


int main(int argc, const char* argv[]) {
  Solution S;
  string s = "abcdefc";
  cout << "Length of longest substring is " << S.lengthOfLongestSubstring(s) << endl;
  return 0;
}

