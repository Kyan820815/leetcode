//--- Q: 0472. Concatenated Words

//--- method 1: dp recursion, better
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        vector<string> res;
        for (auto &word: words) {
            if (dfs(0, word, set) > 1) {
                res.push_back(word);
            }
        }
        return res;
    }
    int dfs(int idx, string &word, unordered_set<string> &set) {
        if (idx == word.size()) {
            return 0;
        }
        string tmp = "";
        for (int i = idx; i < word.size(); ++i) {
            tmp += word[i];
            if (set.find(tmp) == set.end()) {
                continue;
            }
            auto cnt = dfs(i+1, word, set);
            if (cnt != -1) {
                return cnt+1;
            }
        }
        return -1;
    }
};