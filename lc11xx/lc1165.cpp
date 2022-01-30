//--- Q: 1165. Single-Row Keyboard

//--- method 1: record index
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> idx(26, 0);
        for (int i = 0; i < keyboard.size(); ++i) {
            idx[keyboard[i]-'a'] = i;
        }
        int cur = 0, res = 0;
        for (auto &ch: word) {
            res += abs(idx[ch-'a']-cur);
            cur = idx[ch-'a'];
        }
        return res;
    }
};