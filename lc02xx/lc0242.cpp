//--- Q: 0242. Valid Anagram

//--- method 1: record characeter appearance
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> cnt(128, 0);
        for (auto &ch: s) {
            ++cnt[ch];
        }
        for (auto &ch: t) {
            if (--cnt[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};