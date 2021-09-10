//--- Q: 0714. Best Time to Buy and Sell Stock with Transaction Fee

//--- method 1: 2 state finite state machine
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy = max(buy, sell-prices[i]);
            sell = max(sell, buy+prices[i]-fee);
        }
        return sell;
    }
};