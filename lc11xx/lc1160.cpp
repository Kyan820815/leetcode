//--- Q: 1160. Find Words That Can Be Formed by Characters

//--- method 1: track count
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0);
        for (auto &ch: chars) {
            ++cnt[ch-'a'];
        }
        int res = 0;
        for (auto &word: words) {
            auto tmp = cnt;
            int find = 1;
            for (auto &ch: word) {
                if (--tmp[ch-'a'] < 0) {
                    find = 0;
                    break;
                }
            }
            if (find) {
                res += word.size();
            }
        }
        return res;
    }
};