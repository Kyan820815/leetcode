//--- Q: 241. Different Ways to Add Parentheses

//--- method 1: divide & conpuer with memorization
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        unordered_map<int, unordered_map<int, vector<int>>> dp;
        return dfs(0, n-1, dp, input);
    }
    vector<int> dfs(int start, int end, unordered_map<int, unordered_map<int, vector<int>>> &dp, string &input) {
        if (dp[start][end].size()) {
            return dp[start][end];
        }
        vector<int> res;
        int sum = 0;
        for (int i = start; i <= end; ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = dfs(start, i-1, dp, input);
                vector<int> right = dfs(i+1, end, dp, input);
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (input[i] == '+') {
                            res.push_back(left[j] + right[k]);
                        } else if (input[i] == '-') {
                            res.push_back(left[j] - right[k]);
                        } else {
                            res.push_back(left[j] * right[k]);
                        }
                    }
                }
            } else {
                sum = sum * 10 + (input[i]-'0');
            }
        }
        if (!res.size()) {
            res.push_back(sum);
        }
        return dp[start][end] = res;
    }
};