//--- Q: 1165. Single-Row Keyboard

//--- method 1: record index
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> map(26);
        for (int i = 0; i < keyboard.size(); ++i) {
            map[keyboard[i]-'a'] = i;
        }
        int last = 0, res = 0;
        for (auto &ch: word) {
            res += abs(map[ch-'a']-last);
            last = map[ch-'a'];
        }
        return res;
    }
};