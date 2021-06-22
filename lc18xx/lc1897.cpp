//--- Q: 1897. Redistribute Characters to Make All Strings Equal

//--- method 1: count
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        for (auto &word: words) {
            for (auto &ch: word) {
                ++cnt[ch-'a'];
            }
        }
        for (auto &v: cnt) {
            if (v % words.size()) {
                return false;
            }
        }
        return true;
    }
};