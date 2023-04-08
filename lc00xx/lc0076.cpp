//--- Q: 0076. Minimum Window Substring
//--- last written: 2023/04/05

//--- method 1: sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnt(128, 0);
        for (int i = 0; i < t.size(); ++i) {
            ++cnt[t[i]];
        }
        int left = 0, right = 0, times = 0, start, maxlen = INT_MAX;
        while (right < s.size()) {
            times += (--cnt[s[right]] >= 0);
            while (cnt[s[left]] < 0) {
                ++cnt[s[left++]];
            }
            if (times == t.size() && right-left+1 < maxlen) {
                maxlen = right-left+1;
                start = left;
            }
            ++right;
        }
        return maxlen == INT_MAX ? "" : s.substr(start, maxlen);
    }
};
