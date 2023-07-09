//--- Q: 0085. Maximal Rectangle
//--- last written: 2023/07/08

//--- method 1: dp iteration
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = 1;
                if (j) {
                    dp[i][j] += dp[i][j-1];
                }
                int len = INT_MAX;
                for (int k = i; k >= 0 && dp[k][j]; --k) {
                    len = min(len, dp[k][j]);
                    res = max(res, len*(i-k+1));
                }
            }
        }
        return res;
    }
};

//--- method 2: increasing stack implenmentaion
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<int> dp(col+1, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                dp[j] = matrix[i][j] == '0' ? 0 : dp[j]+1;
            }
            vector<int> sk = {-1};
            for (int j = 0; j <= col; ++j) {
                while (sk.back() != -1 && dp[sk.back()] > dp[j]) {
                    int idx = sk.back();
                    sk.pop_back();
                    res = max(res, (j-sk.back()-1)*dp[idx]);
                }
                sk.push_back(j);
            }
        }
        return res;
    }
};
