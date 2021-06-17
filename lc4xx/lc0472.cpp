//--- Q: 472. Concatenated Words

//--- method 1: dp recursion, better
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> set(words.begin(), words.end());
        for (int i = 0; i < words.size(); ++i) {
            if (!words[i].size())
                continue;
            if (dfs(0, words[i], set, 0))
                res.push_back(words[i]);
        }
        return res;
    }
    bool dfs(int pos, string &s, unordered_set<string> &set, int cnt) {
        if (pos == s.size() && cnt >= 2)
            return true;
        for (int i = pos; i < s.size(); ++i) {
            string tmp = s.substr(pos, i-pos+1);
            if (set.find(tmp) != set.end() && dfs(i+1, s, set, cnt+1))
                return true;
        }
        return false;
    }
};

//--- method 2: dp recursion with record times using set
class Solution {
public:
    unordered_map<string, int> map;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        map[""] = 0;
        unordered_set<string> set(words.begin(), words.end());
        for (auto &word: words) {
            if (dfs(word, set) > 1) {
                res.push_back(word);
            }
        }
        return res;
    }
    int dfs(string &word, unordered_set<string> &set) {
        if (map.find(word) != map.end()) {
            return map[word];
        }
        for (int i = 0; i < word.size(); ++i) {
            string now = word.substr(0, i+1);
            if (set.find(now) == set.end()) {
                continue;
            }
            int len;
            string next = word.substr(i+1);
            if ((len=dfs(next, set)) != -1) {
                return map[word] = len+1;
            }
        }
        return map[word] = -1;
    }
};