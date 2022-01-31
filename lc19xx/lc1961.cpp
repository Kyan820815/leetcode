//--- Q: 1961. Check If String Is a Prefix of Array

//--- method 1: string operation
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int idx = 0;
        for (int i = 0; i < words.size() && idx < s.size(); idx += words[i].size(), ++i) {
            if (idx + words[i].size() > s.size()) {
                return false;
            }
            for (int j = 0; j < words[i].size(); ++j) {
                if (words[i][j] != s[j+idx]) {
                    return false;
                }
            }
        }
        return idx == s.size();
    }
};