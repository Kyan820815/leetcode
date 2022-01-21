//--- Q: 1065. Index Pairs of a String

//--- method 1: brute force
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        sort(words.begin(), words.end());
        for (int i = 0; i < text.size(); ++i) {
            for (auto &word: words) {
                if (text.substr(i, word.size()) == word) {
                    res.push_back({i, i+(int)word.size()-1});
                }
            }
        }
        return res;
    }
};

//--- method 2: trie tree
class TNode {
public:
    TNode() {
        isend = false;
        next.resize(26, nullptr);
    }
    bool isend;
    vector<TNode *> next;
};
class Solution {
public:
    TNode *root;
    void insert(string &word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
        }
        now->isend = true;
    }
    void search(string &text, int idx) {
        auto now = root;
        for (int i = idx; i < text.size(); ++i) {
            if (!now->next[text[i]-'a']) {
                return;
            }
            now = now->next[text[i]-'a'];
            if (now->isend) {
                res.push_back({idx, i});
            }
        }
    }
    vector<vector<int>> res;
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        root = new TNode();
        for (auto &word: words) {
            insert(word);
        }
        for (int i = 0; i < text.size(); ++i) {
            search(text, i);
        }
        return res;
    }
};