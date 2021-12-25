//--- Q: 0828. Count Unique Characters of All Substrings of a Given String

//--- method 1: dynamic programming, O(n) space
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), res = 0;
        vector<int> lastloc(128, 0), contribution(128, 0), dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1] - contribution[s[i-1]];
            contribution[s[i-1]] = i-lastloc[s[i-1]];
            dp[i] += contribution[s[i-1]];
            res += dp[i];
            lastloc[s[i-1]] = i;
        }
        return res;
    }
};

//--- method 2: dynamic programming, O(1)
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size(), res = 0, cur = 0;
        vector<int> lastloc(128, -1), contribution(128, 0);
        for (int i = 0; i < n; ++i) {
            cur -= contribution[s[i]];
            contribution[s[i]] = i-lastloc[s[i]];
            cur += contribution[s[i]];
            res += cur;
            lastloc[s[i]] = i;
        }
        return res;
    }
};