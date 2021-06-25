//--- Q: 1816. Truncate Sentence

//--- method 1: count words
class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (++cnt == k) {
                    return s.substr(0, i);
                }
            }
        }
        return "";
    }
};