#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> getCombinations(string &s); 
};

vector<string> Solution::getCombinations(string &s) {
  vector<string> combinations;
  int start = 0, end = s.size() - 1;
  for (; start <= end; start++) {
    string temp = "";
    for (int i = start; i <= end; i++) {
      temp.push_back(s[i]);
      combinations.push_back(temp);
    }
  }
  return combinations;
}

int main(int argc, const char * argv[]) {
  if (!(argc == 2 && argv[0] != NULL && argv[1] != NULL)) {
    cout << "Two arguments are required\nAn example format is ./getCombinations abcde\n";
    return 0;
  }
  Solution S;
  string input(argv[1]);
  vector<string> combinations = S.getCombinations(input);
  for (string temp: combinations) {
    cout << temp << " ";
  }
  cout << endl;
  return 0;
}

