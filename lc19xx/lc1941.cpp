//--- Q: 1941. Check if All Characters Have Equal Number of Occurrences

//--- method 1: bucket sort
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> cnt(26, 0);
        for (auto &ch: s) {
            ++cnt[ch-'a'];
        }
        int times = -1;
        for (int i = 0; i < 26; ++i) {
            if (!cnt[i]) {
                continue;
            }
            if (times == -1) {
                times = cnt[i];
            } else if (times != cnt[i]) {
                return false;
            }
        }
        return true;
    }
};