#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation 
//of the two words, i.e. words[i] + words[j] is a palindrome. 
class Solution {
  public:
/******************Time complexity is O(n2)*************************/
    vector<vector<int>> palindromePairs(vector<string>& words) {
      vector<vector<int>> pairs;
      if (words.size() > 1) {
        for (int i = 0; i < words.size() - 1; i++) {
          for (int j = i + 1; j < words.size(); j++) {
            if (_isThePairPalindrome(words[i], words[j])) pairs.push_back({i, j});            
            if (_isThePairPalindrome(words[j], words[i])) pairs.push_back({j, i});            
          }
        }
      } 
      return pairs;
    }
/******************Time complexity is O(n2)*************************/

/******************Time complexity TBD*************************
    vector<vector<int>> palindromePairs(vector<string>& words) {
      vector<vector<int>> pairs;
      unordered_map<string, int> dict;
      for (int i = 0; i < words.size(); i++) {
        dict[_reverse(words[i])] = i;
      }
      for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
          string subStr = _reverse(words[i].substr(0, j));
        }
      }
      return pairs;
    }

******************Time complexity is TBD*************************/

  private:

    string _reverse(string A) {
      int i = 0;
      int j = A.size() - 1;
      while (i < j) {
        char temp = A[j];
        A[j++] = A[i];
        A[i++] = temp;
      }
      return A;
    }

    bool _isThePairPalindrome(string &A, string &B) {
      string combined = A + B;
      //cout << combined << endl;
      int i = 0;
      int size = combined.size() - 1;
      while (i <= size/2) {
        if (combined[i] != combined[size - i++]) return false; 
      } 
      return true;
    }
};

int main(int argc, const char * argv[]) {
  Solution S;
  /*if (argc != 2) {
    cout << "Insufficient args" <<  endl;
    exit;
  }*/
  vector<string> words{"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> pairs = S.palindromePairs(words);
  cout << "[";
  for (vector<vector<int>>::iterator i = pairs.begin(); i != pairs.end(); i++) {
    cout << "[" << (*i)[0] << ", " << (*i)[1] << "], ";
  }
  cout << "\b" << "\b" << "]" << endl;
  return 0;
}

