//--- Q: 714. Best Time to Buy and Sell Stock with Transaction Fee

//--- method 1: 2 state finite state machine
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
        	int pre_buy = buy;
        	int pre_sell = sell;
        	buy = max(pre_buy, pre_sell-prices[i]);
        	sell = max(pre_sell, pre_buy+prices[i]-fee);
        }
        return sell;
    }
};