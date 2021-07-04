//--- Q: 0121. Best Time to Buy and Sell Stock

//--- method 1: O(n) one pass
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, minv = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (minv > prices[i]) {
                minv = prices[i];
            } else {
                res = max(res, prices[i]-minv);
            }
        }
        return res;
    }
};