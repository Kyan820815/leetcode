//--- Q: 1653. Minimum Deletions to Make String Balanced

//--- method 1: dp O(1) space
class Solution {
public:
    int minimumDeletions(string s) {
        int bcnt = 0, res = 0;
        for (auto &ch: s) {
            if (ch == 'a') {
                res = min(res+1, bcnt);
            } else {
                ++bcnt;
            }
        }
        return res;
    }
};

//--- method 2: dp O(n) space
class Solution {
public:
    int minimumDeletions(string s) {
        int bcnt = 0, res = 0, n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            if (s[i-1] == 'a') {
                dp[i] = min(dp[i-1]+1, bcnt);
            } else {
                dp[i] = dp[i-1];
                ++bcnt;
            }
        }
        return dp[n];
    }
};