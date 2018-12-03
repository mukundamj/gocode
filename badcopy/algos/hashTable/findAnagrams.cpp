#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p);
};

/******************Start- Time complexity = O(mn)**************
vector<int> Solution::findAnagrams(string s, string p) {
  unordered_map<char, int> sMap, pMap;
  vector<int> result;
  if (p.size() > s.size()) return result;
  for (int i = 0; i < p.size(); i++) {
    if (pMap.find(p[i]) == pMap.end()) pMap[p[i]] = 1;
    else pMap[p[i]] += 1; 
    cout << p[i] << endl;
  }
  for (int i = 0; i <= s.size() - p.size(); i++) {
    unordered_map<char, int> temp = pMap;
    for (int j = 0; j < p.size(); j++) {
      if (temp.find(s[i + j]) == temp.end()) break;
      else {
        temp[s[i + j]] -= 1;
        if (temp[s[i + j]] == 0) temp.erase(s[i + j]);
      }
      if (j == p.size() - 1) result.push_back(i);   
      cout << s[i + j] << ", ";
    }
    cout << endl;
  }
  return result;
}
******************End- Time complexity = O(mn)**************/


/******************Start- Time complexity = O(m + n)*************/
vector<int> Solution::findAnagrams(string s, string p) {
  vector<int> result, sMap(26, 0), pMap(26, 0);
  if (p.size() > s.size()) return result;
  for (int i = 0; i < p.size(); i++) {
    pMap[p[i] - 'a']++; 
    sMap[s[i] - 'a']++; 
  } 
  if (pMap == sMap) result.push_back(0);
  for (int i = p.size(); i < s.size(); i++) {
    sMap[s[i] - 'a']++;
    sMap[s[i - p.size()] - 'a']--;
    if (pMap == sMap) result.push_back(i - p.size() + 1);
  }
  
  return result;
}
/******************End- Time complexity = O(m + n)*************/


int main(int argc, const char* argv[]) {
  Solution S;
  string s = "abab";
  string p = "ab";
  vector<int> result = S.findAnagrams(s, p); 
  cout << "The result vector is " << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ", ";
  }
  cout << endl;
  return 0;
}

