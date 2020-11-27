//--- Q: 126. Word Ladder II

//--- method 1: bi-directional BFS
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> paths;
        vector<string> path(1, beginWord);
        int start = 0, end = 1, next = 2;
        unordered_set<string> used[3], notused(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> path_of_word;
        unordered_set<string> curused;
        // edge case: endWord not int wordList
        if (notused.find(endWord) == notused.end())
            return paths;
        notused.erase(beginWord);
        notused.erase(endWord);
        used[start].insert(beginWord);
        used[end].insert(endWord);
        
        // begin used for matin the direction of path_of_word
        bool find = false, begin = true;
        
        while (used[start].size()) {
            for (auto &nowWord: used[start]) {
                for (int i = 0; i < nowWord.size(); ++i) {
                    string tmp = nowWord;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (tmp == nowWord)
                            continue;
                        if (used[end].find(tmp) != used[end].end()) {
                            find = true;
                            if (begin)
                                path_of_word[nowWord].push_back(tmp);
                            else
                                path_of_word[tmp].push_back(nowWord);
                        } else if (notused.find(tmp) != notused.end()) {
                            used[next].insert(tmp);
                            curused.insert(tmp);
                            if (begin)
                                path_of_word[nowWord].push_back(tmp);
                            else
                                path_of_word[tmp].push_back(nowWord);
                        }
                    }
                }
            }
            // delete all used word after current iteration, inorder to make sure all possible words will be reach
            for (auto &word: curused)
                notused.erase(word);
            curused.clear();
            
            swap(next, start);
            used[next].clear();
            if (used[start].size() > used[end].size()) {
                swap(start, end);
                begin = !begin;
            }
            if (find)
                break;
        }
        if (find)
            getPath(beginWord, endWord, path_of_word, path, paths);
        return paths;
    }
    void getPath(string &nowWord, 
                 string &endWord, 
                 unordered_map<string, vector<string>> &next,
                 vector<string> &path, 
                 vector<vector<string>> &paths) {
        if (nowWord == endWord) {
            paths.push_back(path);
            return;
        }
        for (auto &word: next[nowWord]) {
            path.push_back(word);
            getPath(word, endWord, next, path, paths);
            path.pop_back();
        }
    }
};