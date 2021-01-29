//--- Q: 1672. Richest Customer Wealth

//--- method 1: compare row by row
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size(), col = accounts[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            int sum = 0;
            for (int j = 0; j < col; ++j) {
                sum += accounts[i][j];
            }
            res = max(res, sum);
        }
        return res;
    }
};