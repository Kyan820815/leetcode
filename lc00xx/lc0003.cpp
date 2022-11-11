//--- Q: 0003. Longest Substring Without Repeating Characters
//--- last written: 2022/11/01

//--- method 1: sliding window with hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, 0);
        int left = 0, right = 0, res = 0;
        while (right < s.size()) {
            ++cnt[s[right]];
            while (cnt[s[right]] > 1) {
                --cnt[s[left++]];
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};
