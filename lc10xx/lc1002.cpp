//--- Q: 1002. Find Common Characters

//--- method 1: O(n) time find comman ch
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> gcnt(26, INT_MAX);
        for (auto &word: words) {
            vector<int> cnt(26, 0);
            for (auto &ch: word) {
                ++cnt[ch-'a'];
            }
            for (int i = 0; i < 26; ++i) {
                gcnt[i] = min(gcnt[i], cnt[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < gcnt[i]; ++j) {
                string ch(1, 'a'+i);
                res.push_back(ch);
            }
        }
        return res;
    }
};