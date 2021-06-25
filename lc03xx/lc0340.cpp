//--- Q: 340. Longest Substring with At Most K Distinct Characters

//--- method 1: sliding window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnt(128, 0);
        int res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i]]++ == 0)
                --k;
            if (k < 0) {
                while (--cnt[s[left++]] != 0);
                ++k;                
            }
            res = max(res, i-left+1);
        }
        return res;
    }
};