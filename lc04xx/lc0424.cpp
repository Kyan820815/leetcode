//--- Q: 0424. Longest Repeating Character Replacement

//--- method 1: sliding window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left, right, maxv = 0, res = 0;
        vector<int> cnt(26, 0);
        for (left = 0, right = 0; right < s.size(); ++right) {
            maxv = max(maxv, ++cnt[s[right]-'A']);
            if (right-left+1-maxv > k) {
                --cnt[s[left++]-'A'];
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};