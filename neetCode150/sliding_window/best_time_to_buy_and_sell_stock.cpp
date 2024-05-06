/*
PROBLEM (easy)
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104
*/
/*
SOLUTION
Traverse from left to right keeping track of the smallest value seen, and the maximum profit found.
For each value, check if new minimum seen, and if not:
  Check if that value can give you a new max profit.
After loop, return the maximum profit found.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minSeen = prices[0];
        int maxProfit = prices[1] - minSeen;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minSeen){
                minSeen = prices[i];
            } else{
                if(prices[i] - minSeen > maxProfit) maxProfit = prices[i] - minSeen;
            }
        }
        return maxProfit;
    }
};
