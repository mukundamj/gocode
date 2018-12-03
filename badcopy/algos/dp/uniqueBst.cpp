#include <iostream>
#include <vector>

using namespace std;

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.

The logic implemented here is as per the leet code discussion using dynamic programming approach
  The formula to find unique BSTs is as below
  G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
*/

class Solution {
  public:

/*********Recursive approach**********
    int numTrees(int n) {
      storedUniqueBst.resize(n, 0);
      storedUniqueBst[0] = storedUniqueBst[1] = 1;
      int sumUnique = 0;
      for (int i = 1; i <= n; i++) {
        sumUnique += _uniqueBst(i - 1)*_uniqueBst(n - i); 
      }  
      return sumUnique;
    }
  
  private:
    vector<int> storedUniqueBst;
    int _uniqueBst(int n) {
      if (storedUniqueBst[n] != 0) {
        return storedUniqueBst[n];
      }
      for (int i = 1; i <= n; i++) {
        storedUniqueBst[n] += _uniqueBst(i - 1)*_uniqueBst(n - i); 
      }  
      return storedUniqueBst[n];
    }
*********Recursive approach end********/

/************Iterative approach start******/
  int numTrees(int n) {
    vector<int> storedUniqueBst(n + 1, 0);
    storedUniqueBst[0] = storedUniqueBst[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        storedUniqueBst[i] += storedUniqueBst[j - 1]*storedUniqueBst[i - j];
      }
    }  
    return storedUniqueBst[n];
  }
/************Iterative approach end******/

};

int main(int argc, const char * argv[]) {
  Solution S;
  cout << "Running the c++ code " << argv[0] << endl;
  cout << S.numTrees(atoi(argv[1])) << endl;
  return 0;
}

