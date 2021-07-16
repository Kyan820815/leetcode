//--- Q: 0309. Best Time to Buy and Sell Stock with Cooldown

//--- method 1: dp, state machine
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0], sell = 0, cool = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy = max(buy, cool-prices[i]);
            cool = sell;
            sell = max(sell, buy+prices[i]);
        }
        return sell;
    }
};