#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isIsomorphic(string , string );
};

bool Solution::isIsomorphic(string s, string t) {
  if (s.size() != t.size()) return false;
  vector<char> sMap(255, '-'), tMap(255, '-');
  for (int i = 0; i < s.size(); i++) {
    if (sMap[s[i]] == '-') sMap[s[i]] = t[i];
    if (tMap[t[i]] == '-') tMap[t[i]] = s[i];
    if ((sMap[s[i]] != t[i]) || (tMap[t[i]] != s[i])) return false;
  }
  return true;
}



int main(int argc, const char* argv[]) {
  Solution S;
  string s = "aa";
  string t = "ab";
  cout << "Is isomorphic? " <<  S.isIsomorphic(s, t) << endl;
  return 0;
}

