/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (45.74%)
 * Total Accepted:    416.9K
 * Total Submissions: 911K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> memo(prices.size(), 0);

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= prices[i-1]) { memo[i] = memo[i-1]; }
            else {
                int k = i-1;
                while (k > 0 && k != memo[k] && prices[k] >= prices[i]) {
                    k = memo[k];
                }
                if (prices[i] >= prices[k]) { memo[i] = k; }
                else memo[i] = i;
            }
        }

        for (int i = 0; i < prices.size(); i++) {
            memo[i] = prices[i] - prices[memo[i]];
        }

        int maxNum = 0;
        for (int n : memo) {
            maxNum = max(n, maxNum);
        }

        return maxNum;
    }
};
