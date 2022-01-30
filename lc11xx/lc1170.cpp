//--- Q: 1170. Compare Strings by Frequency of the Smallest Character

//--- method 1: bucket sort
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        vector<int> idx(11, 0), res;
        for (auto &word: words) {
            vector<int> cnt(26, 0);
            for (auto &ch: word) {
                ++cnt[ch-'a'];
            }
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    ++idx[cnt[i]];
                    break;
                }
            }
        }
        int sum = 0, prev = 0;
        for (int i = 10; i >= 0; --i) {
            sum += idx[i];
            idx[i] = prev;
            prev = sum;
        }
        for (auto &query: queries) {
            vector<int> cnt(26, 0);
            for (auto &ch: query) {
                ++cnt[ch-'a'];
            }
            int val;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    val = cnt[i];
                    break;
                }
            }
            res.push_back(idx[val]);
        }
        return res;
    }
};