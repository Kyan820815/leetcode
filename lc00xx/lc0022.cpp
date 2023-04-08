//--- Q: 0022. Generate Parentheses
//--- last written: 2023/03/11

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string str = "";
        dfs(0, 0, n, str);
        return res;
    }
    void dfs(int left, int right, int n, string &str) {
        if (right == n) {
            res.push_back(str);
        }
        if (left < n) {
            str += '(';
            dfs(left+1, right, n, str);
            str.pop_back();
        }
        if (right < left) {
            str += ')';
            dfs(left, right+1, n, str);
            str.pop_back();
        }
    }
};

//--- method 2: iteration
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (auto &left: dp[j]) {
                    for (auto &right: dp[i-j-1]) {
                        dp[i].push_back('('+left+')' + right);
                    }
                }
            }
        }
        return dp[n];
    }
};
