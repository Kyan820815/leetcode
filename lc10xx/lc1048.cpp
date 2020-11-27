//--- Q: 1048. Longest String Chain

//--- mehtod 1: dp iteration
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        vector<int> dp(words.size(), 1), mask(words.size(), 0);
        int res = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
                mask[i] |= (1 << (words[i][j]-'a'));
            for (int j = 0; j < i; ++j)
            {
                if (words[i].size()-words[j].size() != 1)
                    continue;
                int and_mask = mask[i]-mask[j];
                if (and_mask < 0) continue;
                int cnt = 0;
                while (and_mask != 0)
                {
                    cnt += and_mask&1;
                    and_mask >>= 1;
                }
                if (cnt == 0 || cnt == 1)
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};