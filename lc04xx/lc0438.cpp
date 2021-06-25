//--- Q: 438. Find All Anagrams in a String

//--- method 1: sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, cnt(128, 0);
        int left = 0, right = 0;
        for (auto &ch: p) {
            ++cnt[ch];
        }
        int times = 0;
        while (right < s.size()) {
            --cnt[s[right]];
            while (cnt[s[right]] < 0) {
                ++cnt[s[left++]];
            }
            if (right-left+1 == p.size()) {
                res.push_back(left);
            }
            ++right;
        }
        return res;
    }
};