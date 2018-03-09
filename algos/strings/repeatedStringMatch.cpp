#include <iostream>
#include <vector>

using namespace std;

//Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. 
//If no such solution, return -1.
//For example, with A = "abcd" and B = "cdabcdab".
//Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring 
//of A repeated two times ("abcdabcd"). 
class Solution {
  public:
    int repeatedStringMatch(string A, string B) {
      for (int i = 0; i < A.size(); i++) {
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

