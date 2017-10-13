#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
  public:
    bool isPerfectSquare(int num) {
      if (num == 1) return true;
      int low = 0; 
      int avg = 0; 
      int high = num;
      while ((high - low) > 1 ) {
        avg = (high - low)/2 + low;
        cout << "High: " << high << " " << "Low: " << low << " " << "Avg: " << avg << endl;
        if ((num % avg == 0) && (num/avg == avg)) return true;
        else if (num/avg <= avg ) high = avg;
        else low = avg;
      }
      return false;
    }
};

int main(int argc, const char * argv[]) {
  if (argc < 2) return 0;
  Solution S;
  cout << S.isPerfectSquare(atoi(argv[1])) << endl;
  return 0;
}

