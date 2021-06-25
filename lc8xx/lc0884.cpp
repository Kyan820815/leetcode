//--- Q: 0884. Uncommon Words from Two Sentences

//--- method 1: find the word appearing once
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map;
        vector<string> res;
        string str = "";
        for (int i = 0; i <= s1.size(); ++i) {
            if (i == s1.size() || s1[i] == ' ') {
                ++map[str];
                str = "";
            } else {
                str += s1[i];
            }
        }
        for (int i = 0; i <= s2.size(); ++i) {
            if (i == s2.size() || s2[i] == ' ') {
                ++map[str];
                str = "";
            } else {
                str += s2[i];
            }
        }
        for (auto &wd: map) {
            if (wd.second == 1) {
                res.push_back(wd.first);
            }
        }
        return res;
    }
};