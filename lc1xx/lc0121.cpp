//--- Q: 121. Best Time to Buy and Sell Stock

//--- method 1: O(n) one pass
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < prices.size(); ++i)
        {
        	if (prices[i] < min)
        		min = prices[i];
        	if (prices[i] - min > max)
        		max = prices[i] - min;
        }
        return max == INT_MIN ? 0 : max;
    }
};