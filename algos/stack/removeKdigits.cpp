#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string removeKdigits(string, int); 
};

//Given a non-negative integer num represented as a string, remove k digits from the number so that 
//the new number is the smallest possible. 
string Solution::removeKdigits(string num, int k) {
  string ans = "";
  for (auto c : num) {
    while (ans.length() && ans.back() > c && k) {
      ans.pop_back();
      k--;
    }
    if (ans.length() || c != '0') ans.push_back(c); //Can't have leading 0's
  }
  while (ans.length() && k--) ans.pop_back(); //If any digits weren't removed in the for loop remove it here until k = 0
  return ans.empty() ? "0" : ans;
}

int main(int argc, const char * argv[]) {
  Solution S;
  cout << "123456789 after removing 4 digits is : " << S.removeKdigits("123456789", 4) << endl;
  cout << "987654321 after removing 4 digits is : " << S.removeKdigits("987654321", 4) << endl;
  return 0;
}

