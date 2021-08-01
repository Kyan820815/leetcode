//--- Q: 0567. Permutation in String

//--- method 1: sliding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26, 0);
        for (auto &ch: s1) {
            ++cnt[ch-'a'];
        }
        for (int left = 0, right = 0; right < s2.size(); ++right) {
            --cnt[s2[right]-'a'];
            while (cnt[s2[right]-'a'] < 0) {
                ++cnt[s2[left++]-'a'];
            }
            if (right-left+1 == s1.size()) {
                return true;
            }
        }
        return false;
    }
};