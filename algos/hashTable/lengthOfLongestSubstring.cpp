#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string );
};
//Given a string, find the length of the longest substring without repeating characters.
int Solution::lengthOfLongestSubstring(string s) {
  if (s.size() == 0) return 0;
  unordered_map<char, bool> sMap;
  int max = 1, begin = 0, end = 1;
  sMap[s[begin]] = true;
  while (end < s.size()) {
    if (sMap.find(s[end]) == sMap.end()) {
      sMap[s[end++]] = true;
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


int main(int argc, const char* argv[]) {
  Solution S;
  string s = "abcbb";
  cout << "Length of longest substring is " << S.lengthOfLongestSubstring(s) << endl;
  return 0;
}

