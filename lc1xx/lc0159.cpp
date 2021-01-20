//--- Q: 159. Longest Substring with At Most Two Distinct Characters

//--- method 1: two pointer
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> cnt(128, 0);
        int right = 0, left = 0, res = 0, diff = 0;
        while (right < s.size()) {
            if (++cnt[s[right]] == 1) {
                ++diff;
            }
            while (diff > 2) {
                if (!--cnt[s[left++]]) {
                    --diff;
                }
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};