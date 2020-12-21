//--- Q: 003. Longest Substring Without Repeating Characters

//--- method 1: sliding window with vecetor, better if else case & time (cuase use vector instead of hash)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, -1);
        int left = 0, right = 0, maxv = 0;
        while (right < s.size())
        {
            if (cnt[s[right]] >= left)
                left = cnt[s[right]]+1;
            cnt[s[right]] = right;
            maxv = max(maxv, right-left+1);
            ++right;
        }
        return maxv;
    }
};

//--- method 2: sliding window with hashmap
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
