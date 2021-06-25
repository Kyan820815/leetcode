//--- Q: 122. Best Time to Buy and Sell Stock II

//--- method 1: state machine
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int s_sell = 0, s_buy = -prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
        	int pre_sell = s_sell;
        	int pre_buy = s_buy;
        	s_sell = max(s_sell, s_buy+prices[i]);
        	s_buy = max(s_buy, s_sell-prices[i]);
        }
        return s_sell;
    }
};

//--- method 2: state machine, another view
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxv = 0, buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            buy = min(buy, sell-prices[i]);
            sell = max(sell, buy+prices[i]);
        }
        return sell;
    }
};