//--- Q: 309. Best Time to Buy and Sell Stock with Cooldown

//--- method 1: dp, state machine
class Solution {
public:
    int maxProfit(vector<int>& prices) {
  	    if (prices.size() == 0) return 0;
    	int S_rest = 0, S_buy = 0-prices[0], S_sell = 0;
    	for (int i = 1; i < prices.size(); ++i)
    	{
    		int pre_rest = S_rest;
    		int pre_buy = S_buy;
    		int pre_sell = S_sell;
    		S_rest = max(pre_rest, pre_sell);
    		S_buy = max(pre_buy, pre_rest-prices[i]);
    		S_sell = pre_buy+prices[i];
    	}
    	return max(S_rest, S_sell);
    }
};