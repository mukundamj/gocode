#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> topKFrequent(vector<string>& words, int k);
};

struct comparePairs {
  bool operator() (const pair<string, int>& a, const pair<string, int>& b)
  {
    if (a.second > b.second) return true; 
    else if (a.second == b.second) {
      return (a.first < b.first);
    }
    else return false;
  }
};

vector<string> Solution::topKFrequent(vector<string>& words, int k) {
  map<string, int> words_count_map;
  vector<pair<string, int>> words_count_vec; 
  vector<string> res;
  for (auto s : words) {
    if (words_count_map.find(s) == words_count_map.end()) {
      words_count_map[s] = 1; 
    }
    else words_count_map[s]++;
  }

  for (auto p : words_count_map) {
    words_count_vec.emplace_back(p.first, p.second);
  }

  //Sorting the vector with custom comparator class
  //The time required to run when compare class is used is high compared to
  //using lambda function
  //sort (words_count_vec.begin(), words_count_vec.end(), comparePairs());

  //Sorting the vector using custom comparator lambda function
  sort
  (
    words_count_vec.begin(), words_count_vec.end(), 
    [](const pair<string, int>& a, const pair<string, int>& b)
    {
      if (a.second > b.second) return true; 
      else if (a.second == b.second) {
        return (a.first < b.first);
      }
      else return false;
    }
  );

  for (int i = 0; i < k; i++) {
    res.push_back(words_count_vec[i].first); 
  }
  
  return res;
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<string> list_of_strings = {"the", "day", "is", "sunny", "the", "the",
     "the", "sunny", "is", "is"
  };
  vector<string> result = S.topKFrequent(list_of_strings, 2);
  for (auto s : result) {
    cout << s << '\n';
  }
  return 0;
}
