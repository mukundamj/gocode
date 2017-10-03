#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int repeatedStringMatch(string A, string B) {
      for (int i = 0, j = 0; i < A.size(); i++) {
        for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j) {
          cout << A[(i + j) % A.size()] << " " << B[j] << endl;
          if ((j + 1) == B.size()) return ((i + j + 1) / A.size()) + ((i + j + 1) % A.size() > 0 ? 1 : 0);
        }
      }
      return -1;
    }
};

int main(int argc, const char * argv[]) {
  Solution S;
  string A = "a";
  string B = "aa";
  cout << S.repeatedStringMatch(A, B) << endl;
  return 0;
}

