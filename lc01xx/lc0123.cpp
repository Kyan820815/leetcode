//--- Q: 123. Best Time to Buy and Sell Stock III

//--- method 1: dp solution, space:O(kn)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> sell(2, vector<int>(n, 0));
        for (int k = 0; k < 2; ++k) {
            int buy = -prices[0];
            for (int i = 1; i < n; ++i) {
                int last_transc = !k || i < 2 ? 0 : sell[k-1][i-2];
                int last_no_transc = !i ? 0 : sell[k][i-1];
                buy = max(buy, last_transc-prices[i-1]);
                sell[k][i] = max(last_no_transc, buy+prices[i]);
            }
        }
        return sell[1].back();
    }
};

//--- method 2-1: dp solution, space:O(k)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(3, 0), buy(3, -prices[0]);
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= 2; ++k) {
                buy[k] = max(buy[k], sell[k-1]-prices[i]);
                sell[k] = max(sell[k], buy[k]+prices[i]);
            }
        }
        return sell.back();
    }
};

//--- method 2-2: use variable
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), sell1 = 0, sell2 = 0, buy1 = -prices[0], buy2 = -prices[0];
        for (int i = 1; i < n; ++i) {
        	buy1 = max(buy1, -prices[i]);
        	sell1 = max(sell1, buy1+prices[i]);
        	buy2 = max(buy2, sell1-prices[i]);
        	sell2 = max(sell2, buy2+prices[i]);
        }
        return sell2;
    }
};