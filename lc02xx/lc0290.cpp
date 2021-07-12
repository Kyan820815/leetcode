//--- Q: 0290. Word Pattern

//--- method 1: double hashmap to record 1 to 1 relation
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> fw;
        unordered_map<string, char> bw;
        string str = "";
        int j = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (fw.find(pattern[j]) == fw.end()) {
                    fw[pattern[j]] = str;
                    if (bw.find(str) != bw.end()) {
                        return false;
                    }
                    bw[str] = pattern[j];
                } else if (fw[pattern[j]] != str) {
                    return false;
                }
                ++j;
                str = "";
            } else {
                str += s[i];
            }
        }
        return j == pattern.size();
    }
};