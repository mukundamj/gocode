#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

class Solution {

/*  Time complexity is O(n2)
  public:
    int findMinDifference(vector<string>& timePoints) {
      int minDiff = 10000;
      for (int i = 0; i < timePoints.size(); i++) {
        for (int j = i + 1; j < timePoints.size(); j++) {
          int diff = _findDiff(timePoints[i].c_str(), timePoints[j].c_str());
          minDiff = minDiff <  diff ? minDiff : diff;
        }
      }
      return minDiff;
    }

  private:
    int _findDiff(const char * A, const char * B) {
      int secondsA = (((A[0] - '0') * 10 + (A[1] - '0')) * 60) + ((A[3] - '0') * 10 + (A[4] - '0'));
      int secondsB = (((B[0] - '0') * 10 + (B[1] - '0')) * 60) + ((B[3] - '0') * 10 + (B[4] - '0'));
      int delta = abs(secondsA - secondsB);
      return  delta > 720 ? (1440 - delta) : delta;
    }
*/

/******Time complexity is O(n + nlogn)***********/
  
//Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference 
//between any two time points in the list. 
  public:
    int findMinDifference(vector<string>& timePoints) {
      int minDiff = 10000;
      int size = timePoints.size();
      int diff;
      sort(timePoints.begin(), timePoints.end());
      for (int i = 0; i + 1 < size; i++) {
        diff = _findDiff(timePoints[i + 1].c_str(), timePoints[i].c_str());
        minDiff = minDiff <  diff ? minDiff : diff;
      }
      diff = _findDiff(timePoints[size - 1].c_str(), timePoints[0].c_str());
      minDiff = minDiff < diff ? minDiff : diff;
      return minDiff;
    }

  private:
    int _findDiff(const char * A, const char * B) {
      int minutesA = (((A[0] - '0') * 10 + (A[1] - '0')) * 60) + ((A[3] - '0') * 10 + (A[4] - '0'));
      int minutesB = (((B[0] - '0') * 10 + (B[1] - '0')) * 60) + ((B[3] - '0') * 10 + (B[4] - '0'));
      int delta = (minutesA - minutesB);
      return  delta > 720 ? (1440 - delta) : delta;
    }

};

int main(int argc, const char * argv[]) {
  Solution S;
  //vector<string> timePoints = {"23:59", "00:59", "11:31", "23:01", "12:00"};
  vector<string> timePoints = {"05:31","22:08","00:35"};
  cout << S.findMinDifference(timePoints) << endl;
  return 0;
}

