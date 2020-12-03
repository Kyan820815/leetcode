//--- Q: 1048. Longest String Chain

//--- mehtod 1: dp iteration
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int maxv = 1;
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        for (int i = 0; i < words.size(); ++i) {
            dp[words[i]] = 1;
            for (int j = 0; j < words[i].size(); ++j) {
                string last_str = words[i].substr(0, j) + words[i].substr(j+1);
                if (dp.find(last_str) != dp.end()) {
                    dp[words[i]] = max(dp[words[i]], dp[last_str]+1);
                }
            }
            maxv = max(maxv, dp[words[i]]);
        }
        return maxv;
    }
};