//--- Q: 0395. Longest Substring with At Least K Repeating Characters

//--- method 1: left right partition
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (!s.size()) {
            return 0;
        }
        vector<int> cnt(26, 0);
        for (auto &ch: s) {
            ++cnt[ch-'a'];
        }
        int i, j;
        for (i = 0; i < s.size() && cnt[s[i]-'a'] >= k; ++i);
        if (i == s.size()) {
            return i;
        }
        for (j = i; j < s.size() && cnt[s[j]-'a'] < k; ++j);
        return max(longestSubstring(s.substr(0,i), k), longestSubstring(s.substr(j), k));
    }
};