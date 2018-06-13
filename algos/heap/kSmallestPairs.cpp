#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int>&, vector<int>&, int); //Uses priority_queue to implement heap
};

struct comparePairsForQueue {
  comparePairsForQueue (vector<int> &nums1, vector<int> &nums2) : _nums1(nums1), _nums2(nums2) {}
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return (_nums1[a.first] + _nums2[a.second] > _nums1[b.first] + _nums2[b.second]);
  }
  vector<int> &_nums1, &_nums2;
};
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums. 
*/
vector<pair<int, int>> Solution::kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  vector<pair<int, int>> result;
  if (nums1.empty() || nums2.empty() || k <= 0) return result;
  //The compare class for priority_queue could be a function or a struct. The below 4 lines uses
  //lambda function
  /*
  auto comp = [nums1, nums2] (pair<int, int> a, pair<int, int> b) {
    return (nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]); 
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
  */

  //The following approach using a comparePairs struct for ordering the elements in the priority_queue
  priority_queue<pair<int, int>, vector<pair<int, int>>, comparePairsForQueue> min_heap(comparePairsForQueue(nums1, nums2));
  min_heap.emplace(0, 0);
  while (k-- > 0 && min_heap.size()) {
    auto index = min_heap.top();
    min_heap.pop();
    printf("index.first = %d, index.second = %d\n", index.first, index.second);
    result.emplace_back(nums1[index.first], nums2[index.second]);
    if (index.first + 1 < nums1.size()) {
      min_heap.emplace(index.first + 1, index.second);
    }
    if (index.first == 0 && index.second + 1 < nums2.size()) {
      min_heap.emplace(index.first, index.second + 1);
    }
  }
  return result;
}

int main(int argc, const char * argv[]) {
  Solution S;
  vector<int> nums1 = {1, 1, 2};
  vector<int> nums2 = {1, 2, 3};
  vector<pair<int,int>> result = S.kSmallestPairs(nums1, nums2, 3);
  for (auto p : result) {
    printf("(%d, %d)  ", p.first, p.second);
  }
  cout << endl;
  return 0;
}

