//--- Q: 0127. Word Ladder

//--- method 1: single way bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> pool(wordList.begin(), wordList.end());
        unordered_set<string> que;
        que.insert(beginWord);
        if (pool.find(endWord) == pool.end()) {
            return 0;
        }
        pool.erase(beginWord);
        pool.erase(endWord);
        int res = 0;
        while (que.size()) {
            unordered_set<string> next;
            for (auto &curWord: que) {
                for (int i = 0; i < curWord.size(); ++i) {
                    auto nextWord = curWord;
                    for (int j = 0; j < 26; ++j) {
                        nextWord[i] = j+'a';
                        if (nextWord == curWord) {
                            continue;
                        }
                        if (nextWord == endWord) {
                            return res+2;
                        } else if (pool.find(nextWord) != pool.end()) {
                            next.insert(nextWord);
                            pool.erase(nextWord);
                        }
                    }
                }
            }
            que = next;
            ++res;
        }
        return 0;
    }
};

//--- method 2: bi-directional bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> pool(wordList.begin(), wordList.end());
        vector<unordered_set<string>> data(3);
        int start = 0, end = 1, next = 2;
        if (pool.find(endWord) == pool.end()) {
            return 0;
        }
        data[start].insert(beginWord);
        pool.erase(beginWord);
        pool.erase(endWord);
        data[start].insert(beginWord);
        data[end].insert(endWord);
        int res = 0;
        while (data[start].size()) {
            for (auto &curWord: data[start]) {
                for (int i = 0; i < curWord.size(); ++i) {
                    auto nextWord = curWord;
                    for (int j = 0; j < 26; ++j) {
                        nextWord[i] = j+'a';
                        if (nextWord == curWord) {
                            continue;
                        }
                        if (data[end].find(nextWord) != data[end].end()) {
                            return res+2;
                        } else if (pool.find(nextWord) != pool.end()) {
                            data[next].insert(nextWord);
                            pool.erase(nextWord);
                        }
                    }
                }
            }
            data[start] = data[next];
            data[next].clear();
            if (data[start].size() > data[end].size()) {
                swap(start, end);
            }
            ++res;
        }
        return 0;
    }
};

