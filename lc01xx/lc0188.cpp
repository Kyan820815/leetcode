//--- Q: 0188. Best Time to Buy and Sell Stock IV

//--- method 1: dp solution, state machine
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (!prices.size()) {
            return 0;
        }
        vector<int> sell(k+1, 0), buy(k+1, -prices[0]);
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], buy[j]+prices[i]);
            }
        }
        return sell.back();
    }
};