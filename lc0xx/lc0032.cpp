//--- Q: 0032. Longest Valid Parentheses

//--- method 1: stack
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> sk = {-1};
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push_back(i);
            } else {
                if (sk.back() != -1 && s[sk.back()] == '(') {
                    sk.pop_back();
                } else {
                    sk.push_back(i);
                }
            }
        }
        int now = s.size();
        while (sk.size()) {
            res = max(res, now-sk.back()-1);
            now = sk.back();
            sk.pop_back();
        }
        return res;
    }
};

//--- method 2: dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; ++i) {
            if (s[i-1] == ')') {
                if (s[i-2] == '(') {
                    dp[i] = dp[i-2] + 2;
                } else if (s[i-2] == ')' && i-2-dp[i-1] >= 0 && s[i-dp[i-1]-2] == '(') {
                    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};