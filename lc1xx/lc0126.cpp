//--- Q: 126. Word Ladder II

//--- method 1: bi-directional BFS
class Solution {
public:
    unordered_map<string, vector<string>> rel;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<unordered_set<string>> set(3);
        int start = 0, end = 1, next = 2;
        unordered_set<string> pool(wordList.begin(), wordList.end());
        vector<vector<string>> res_vec;
        vector<string> res = {beginWord};
        if (pool.find(endWord) == pool.end()) {
            return {};
        }
        pool.erase(beginWord);
        pool.erase(endWord);
        set[start].insert(beginWord);
        set[end].insert(endWord);
        while (set[start].size()) {
            bool find = false;
            for (auto &s: set[start]) {
                for (int i = 0; i < s.size(); ++i) {
                    string str = s;
                    for (int j = 0; j < 26; ++j) {
                        if (j == s[i]-'a') {
                            continue;
                        }
                        str[i] = j+'a';
                        if (set[end].find(str) != set[end].end()) {
                            if (start < end) {
                                rel[s].push_back(str);
                            } else {
                                rel[str].push_back(s);
                            }
                            find = true;
                        } else if (pool.find(str) != pool.end()) {
                            set[next].insert(str);
                            if (start < end) {
                                rel[s].push_back(str);
                            } else {
                                rel[str].push_back(s);
                            }
                        }
                    }
                }
            }
            if (find) {
                dfs(beginWord, endWord, res, res_vec);
                break;
            } else {
                for (auto &t: set[next]) {
                    pool.erase(t);
                }
                swap(set[start], set[next]);
                set[next].clear();
                if (set[start].size() > set[end].size()) {
                    swap(start, end);
                }
            }
        }
        return res_vec;
    }
    void dfs(string &now, string &endWord, vector<string> &res, vector<vector<string>> &res_vec) {
        if (now == endWord) {
            res_vec.push_back(res);
            return;
        }
        for (int i = 0; i < rel[now].size(); ++i) {
            res.push_back(rel[now][i]);
            dfs(rel[now][i], endWord, res, res_vec);
            res.pop_back();
        }
    }
};