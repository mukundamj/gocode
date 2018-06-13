#include <iostream>
#include <vector>

//I repliied this as a solution to leetcode question
using namespace std;

class Solution {
  public:
    vector<string> getCombinations(string &);
    void getCombinations(string &, int, int, vector<string> &);
};

vector<string> Solution::getCombinations(string &s) {
  vector<string> combinations;
  getCombinations(s, 0, (s.size() - 1), combinations);
  return combinations;
}

void Solution::getCombinations(string &s, int start, int end, vector<string> &combinations) {
  if (start == end) {
    combinations.push_back("");
    combinations.push_back(s[end]);
    return;
  }
  getCombinations(s, start + 1, end, combinations);
  int size = combinations.size();
  for (int i = 0; i < size; i++) {
    combinations.push_back(s[start] + combinations[i]);
  }
  return;
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
