//--- Q: 0159. Longest Substring with At Most Two Distinct Characters

//--- method 1: two pointer
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = 0, n = s.size(), res = 0, unique = 0;
        vector<int> cnt(128, 0);
        while (right < n) {
            unique += (++cnt[s[right]] == 1);
            while (unique > 2) {
                unique -= (!--cnt[s[left++]]);
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};