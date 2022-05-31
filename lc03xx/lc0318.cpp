//--- Q: 0318. Maximum Product of Word Lengths

//--- method 1: bit manipulation
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> map;
        int res = 0;
        for (auto &word: words) {
            int h = 0, n = word.size();
            for (auto &ch: word) {
                h = h | (1<< (ch-'a'));
            }
            for (auto &[hash, len]: map) {
                if (!(hash&h)) {
                    res = max(res, n*len);
                }
            }
            map[h] = max(map[h], n);
        }
        return res;
    }
};