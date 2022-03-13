//--- Q: 0290. Word Pattern

//--- method 1: double hashmap to record 1 to 1 relation
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word = "";
        unordered_map<string, char> fw;
        unordered_map<char, string> bw;
        int i, j;
        for (i = 0, j = 0; i <= s.size() && j < pattern.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (fw.find(word) == fw.end()) {
                    fw[word] = pattern[j];
                    if (bw.find(pattern[j]) != bw.end()) {
                        return false;
                    }
                    bw[pattern[j]] = word;
                } else if (fw[word] != pattern[j]) {
                    return false;
                }
                word = "";
                ++j;
            } else {
                word += s[i];
            }
        }
        return j == pattern.size();
    }
};