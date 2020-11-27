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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> set(words.begin(), words.end());
        for (int i = 0; i < words.size(); ++i) {
            unordered_map<int, int> map;
            if (dfs(0, words[i], map, set) > 1)
                res.push_back(words[i]);
        }
        return res;
    }
    int dfs(int pos, string &now, unordered_map<int, int> &map, unordered_set<string> &set) {
        if (map.find(pos) != map.end())
            return map[pos];
        if (pos == now.size())
            return map[pos] = 0;
        for (int i = pos; i < now.size(); ++i) {
            string tmp = now.substr(pos, i-pos+1);
            if (set.find(tmp) == set.end())
                continue;
            int next_len = dfs(i+1, now, map, set);
            if (next_len != -1)
                return map[pos] = next_len + 1;

        }
        return map[pos] = -1;
    }
};