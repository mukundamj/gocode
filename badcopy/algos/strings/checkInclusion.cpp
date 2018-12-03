#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool checkInclusion(string, string);
};

bool Solution::checkInclusion(string s1, string s2) {
  if (s1.size() > s2.size()) return false;
  vector<int> s1Map(26, 0), s2Map(26, 0);
  int start = 0, end = s1.size() - 1;
  for (int i = 0; i < s1.size(); i++) {
    s1Map[s1[i] - 'a'] += 1;
    s2Map[s2[i] - 'a'] += 1;
  }
  if (s1Map == s2Map) return true;
  for (; (end + 1) < s2.size(); start++, end++) {
    s2Map[s2[start] - 'a'] -= 1;
    s2Map[s2[end + 1] - 'a'] += 1;
    if (s2Map == s1Map) return true;
  }
  return false;
}

int main(int argc, const char * argv[]) {
  Solution S;
  if (argc != 3) {
    cout << "Insufficient args" <<  endl;
    exit;
  }
  string s1(argv[1]), s2(argv[2]); 
  //string s1("ab"), s2("abcd"); 
  cout << "s1 string is " << s1 << ", " << "s2 string is " << s2 << endl;
  cout << "Is s1 a substring of s2? " << S.checkInclusion(s1, s2) << endl;
  return 0;
}

