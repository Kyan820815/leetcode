//--- Q: 0126. Word Ladder II
//--- last written: 2023/07/14

//--- method 1: bi-directional BFS
class Solution {
public:
    unordered_map<string, vector<string>> rel;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> pool(wordList.begin(), wordList.end());
        vector<unordered_set<string>> data(3);
        int start = 0, next = 1, end = 2;
        if (pool.find(endWord) == pool.end()) {
            return {};
        }
        pool.erase(beginWord);
        pool.erase(endWord);
        data[start].insert(beginWord);
        data[end].insert(endWord);
        while (data[start].size()) {
            bool find = false;
            for (auto &curWord: data[start]) {
                for (int i = 0; i < curWord.size(); ++i) {
                    auto nextWord = curWord;
                    for (int j = 0; j < 26; ++j) {
                        nextWord[i] = j+'a';
                        if (nextWord == curWord) {
                            continue;
                        }
                        if (data[end].find(nextWord) != data[end].end()) {
                            if (start < end) {
                                rel[curWord].push_back(nextWord);
                            } else {
                                rel[nextWord].push_back(curWord);
                            }
                            find = true;
                        } else if (pool.find(nextWord) != pool.end()) {
                            data[next].insert(nextWord);
                            if (start < end) {
                                rel[curWord].push_back(nextWord);
                            } else {
                                rel[nextWord].push_back(curWord);
                            }
                        }
                    }
                }
            }
            if (find) {
                break;
            }
            for (auto &word: data[next]) {
                pool.erase(word);
            }
            data[start] = data[next];
            data[next].clear();
            if (data[start].size() > data[end].size()) {
                swap(start, end);
            }
        }
        vector<vector<string>> res_vec;
        vector<string> res = {beginWord};
        dfs(beginWord, endWord, res, res_vec);
        return res_vec;
    }
    void dfs(string &curWord, string &endWord, vector<string> &res, vector<vector<string>> &res_vec) {
        if (curWord == endWord) {
            res_vec.push_back(res);
            return;
        }
        for (auto &nextWord: rel[curWord]) {
            res.push_back(nextWord);
            dfs(nextWord, endWord, res, res_vec);
            res.pop_back();
        }
    }
};
