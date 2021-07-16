//--- Q: 0340. Longest Substring with At Most K Distinct Characters

//--- method 1: sliding window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnt(128, 0);
        int res = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            k -= ++cnt[s[right]] == 1;
            while (k < 0) {
                k += !--cnt[s[left++]];
            }
            res = max(res, right-left+1);
        }
        return res;      
    }
};