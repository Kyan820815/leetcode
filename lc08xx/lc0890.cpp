//--- Q: 0890. Find and Replace Pattern

//--- method 1: bijection vector
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto &word: words) {
            vector<int> fw(26, -1), bw(26, -1);
            int find = 1;
            for (int i = 0; i < word.size(); ++i) {
                if (fw[word[i]-'a'] == -1) {
                    fw[word[i]-'a'] = pattern[i]-'a';
                    if (bw[pattern[i]-'a'] != -1) {
                        find = 0;
                        break;
                    }
                    bw[pattern[i]-'a'] = word[i]-'a';
                } else if (fw[word[i]-'a'] != pattern[i]-'a') {
                    find = 0;
                    break;
                }
            }
            if (find) {
                res.push_back(word);
            }
        }
        return res;
    }
};