//--- Q: 1525. Number of Good Ways to Split a String

//--- method 1: dp two pass
class Solution {
public:
    int numSplits(string s) {
        vector<int> dp(s.size(), 0), cnt(26, 0);
        int unique = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            unique += (++cnt[s[i]-'a'] == 1);
            dp[i] = unique;
        }
        cnt.clear();
        cnt.resize(26, 0);
        unique = 0;
        for (int i = s.size()-1; i >= 1; --i) {
            unique += (++cnt[s[i]-'a'] == 1);
            res += unique == dp[i-1];
        }
        return res;
    }
};