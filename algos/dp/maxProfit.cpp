#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> , int);
};

//For algorithm refer to the link https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/
int Solution::maxProfit(vector<int> prices, int fee) {
  int maxHoldProfit = -9999999, maxSellProfit = 0;
  for (int i = 0; i < prices.size(); i++) {
    int temp = maxSellProfit;
    maxSellProfit = max(maxSellProfit, maxHoldProfit + prices[i]);
    maxHoldProfit = max(maxHoldProfit, temp - prices[i] - fee);    
    cout << "maxHoldProfit = " << maxHoldProfit << ", maxSellProfit = " << maxSellProfit << endl;
  }
  return maxSellProfit;
}
 

int main() {
  Solution S;
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int fees = 2;
  cout << S.maxProfit(prices, fees) << endl;
  return 0;
}

