//--- Q: 0916. Word Subsets

//--- method 1: bucket sort
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cnt(26);
        vector<string> res;
        for (auto &word: words2) {
            vector<int> tmpcnt(26);
            for (auto &ch: word) {
                ++tmpcnt[ch-'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = max(cnt[i], tmpcnt[i]);
            }
        }
        for (auto &word: words1) {
            vector<int> tmpcnt(26);
            for (auto &ch: word) {
                ++tmpcnt[ch-'a'];
            }
            int valid = 1;
            for (int i = 0; i < 26; ++i) {
                if (tmpcnt[i] < cnt[i]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                res.push_back(word);
            }
        }
        return res;
    }
};
