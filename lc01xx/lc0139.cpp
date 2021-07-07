//--- Q: 0139. Word Break

//--- method1: dp iteration
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= -1; --j) {
                if ((j == -1 || dp[j]) && set.find(s.substr(j+1, i-j)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};