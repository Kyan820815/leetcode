//--- Q: 0500. Keyboard Row

//--- method 1: find if all are in the same line
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> pos(128, 0);
        vector<string> str(3);
        str[0] = "qwertyuiop";
        str[1] = "asdfghjkl";
        str[2] = "zxcvbnm";
        for (int i = 0; i < 3; ++i) {
            for (auto &ch: str[i]) {
                pos[ch] = pos[ch^32] = i;
            }
        }
        vector<string> res;
        for (auto &word: words) {
            bool valid = true;
            for (auto &ch: word) {
                if (pos[ch] != pos[word[0]]) {
                    valid = false;
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