//--- Q: 0123. Best Time to Buy and Sell Stock III

//--- method 1: dp solution, space:O(k)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(3, -prices[0]), sell(3, 0);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= 2; ++j) {
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j]+prices[i]);
            }
        }
        return sell[2];
    }
};

//--- method 2: use variable
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(3, -prices[0]), sell(3, 0);
        int buy1 = -prices[0], sell1 = 0, buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1+prices[i]);
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2;
    }
};