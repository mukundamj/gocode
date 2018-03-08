#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
  public:
    bool judgeSquareSum(int c) {
      int right = sqrt(c); 
      int left = 0;
      while (left <= right) {
        left = int(sqrt(c - (right * right)));
        if ((left * left + right * right) == c)  return true;  
        right--;
      }
      return false;
    }
};

int main(int argc, const char * argv[]) {
  if (argc < 2) return 0;
  Solution S;
  cout << S.judgeSquareSum(atoi(argv[1])) << endl;
  return 0;
}

