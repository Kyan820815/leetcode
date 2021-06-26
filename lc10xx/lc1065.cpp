//--- Q: 1065. Index Pairs of a String

//--- method 1: brute force
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for (auto &word: words) {
            int len = word.size();
            for (int i = 0; i <= (int)text.size()-len; ++i) {
                if (text.substr(i, len) == word) {
                    res.push_back({i, i+len-1});
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//--- method 2: trie tree
class TNode {
public:
    TNode() {
        isend = false;
        next.resize(26, NULL);
    }
    vector<TNode *> next;
    bool isend;
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
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        root = new TNode();
        for (auto &wd: words) {
            insert(wd);
        }
        vector<vector<int>> res;
        for (int i = 0; i < text.size(); ++i) {
            auto now = root;
            for (int j = i; j < text.size() && now; ++j) {
                now = now->next[text[j]-'a'];
                if (now && now->isend) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};