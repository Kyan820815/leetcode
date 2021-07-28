//--- Q: 0438. Find All Anagrams in a String

//--- method 1: sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left, right;
        vector<int> cnt(26, 0);
        for (auto &ch: p) {
            ++cnt[ch-'a'];
        }
        vector<int> res;
        for (left = 0, right = 0; right < s.size(); ++right) {
            --cnt[s[right]-'a'];
            for (; cnt[s[right]-'a'] < 0;) {
                ++cnt[s[left++]-'a'];
            }
            if (right-left+1 == p.size()) {
                res.push_back(left);
            }
        }
        return res;
    }
};