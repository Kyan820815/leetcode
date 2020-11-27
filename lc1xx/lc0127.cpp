//--- Q: 127. Word Ladder

//--- method 1: bi-directional bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> notused(wordList.begin(), wordList.end());
        unordered_set<string> used[3];
        int start = 0, end = 1, next = 2, res = 2;
        used[start].insert(beginWord);
        used[end].insert(endWord);
        if (notused.find(endWord) == notused.end())
            return 0;
        notused.erase(endWord);
        
        while (used[start].size()) {
            for (auto &word: used[start]) {
                for (int i = 0; i < word.size(); ++i) {
                    string tmp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (tmp == word)
                            continue;
                        if (used[end].find(tmp) != used[end].end())
                            return res;
                        else if (notused.find(tmp) != notused.end()){
                            used[next].insert(tmp);
                            notused.erase(tmp);
                        }
                    }
                }
            }
            swap(start, next);
            if (used[start].size() > used[end].size())
                swap(start, end);
            used[next].clear();
            ++res;
        }
        return 0;
    }
};

//--- method 2: O(k*26)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string> que;
        que.push(beginWord);
        int qsize = que.size(), res = 0;
        while (que.size()) {
            ++res;
            for (int i = 0; i < qsize; ++i) {
                string now = que.front();
                que.pop();
                if (now == endWord)
                    return res;
                for (int j = 0; j < now.size(); ++j) {
                    string tmp = now;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[j] = c;
                        if (set.find(tmp) != set.end() && tmp != now) {
                            que.push(tmp);
                            set.erase(tmp);
                        }
                    }
                }
            }
            qsize = que.size();
        }
        return 0;
    }
};

//--- method 3: O(n*k)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        vector<int> visit(len, 1);
        queue<int> que;
        for (int i = 0; i < len; ++i) {
            if (comp(beginWord, wordList[i]) == 1) {
                visit[i] = 0;
                que.push(i);
            }
        }
        int qsize = que.size(), res = 0;
        while (qsize) {
            ++res;
            for (int i = 0; i < qsize; ++i) {
                int cur = que.front();
                que.pop();
                if (wordList[cur] == endWord)
                    return res + 1;
                for (int j = 0; j < len; ++j) {
                    if (!visit[j])
                        continue;
                    if (comp(wordList[cur], wordList[j]) == 1) {
                        visit[j] = 0;
                        que.push(j);
                    }
                }
            }
            qsize = que.size();
        }
        return 0;
    }
    int comp(string &a, string &b) {
        int res = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                ++res;
            if (res > 1)
                return res;
        }
        return res;
    }
};

