//--- Q: 0032. Longest Valid Parentheses
//--- last written: 2022/11/21

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
        vector<int> dp(n);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                int last = i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0;
                dp[i] = last+dp[i-1]+2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
