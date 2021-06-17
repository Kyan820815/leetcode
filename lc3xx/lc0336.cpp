//--- Q: 336. Palindrome Pairs

//--- method 1: trie tree
class TNode {
public:
    TNode() {
        next.resize(26, NULL);
        index = -1;
        list.clear();
    }
    int index;
    vector<TNode *> next;
    vector<int> list;
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        root = new TNode();
        for (int i = 0; i < words.size(); ++i) {
            addword(words[i], i);
        }
        for (int i = 0; i < words.size(); ++i) {
            search(words[i], res, i);
        }
        return res;
    }
    void addword(string &str, int idx) {
        auto now = root;
        for (int i = str.size()-1; i >= 0; --i) {
            if (!now->next[str[i]-'a']) {
                now->next[str[i]-'a'] = new TNode();
            }
            if (ispal(str, 0, i)) {
                now->list.push_back(idx);
            }
            now = now->next[str[i]-'a'];
        }
        now->index = idx;
        now->list.push_back(idx);
    }
    void search(string &str, vector<vector<int>> &res, int idx) {
        auto now = root;
        for (int i = 0; i < str.size(); ++i) {
            if (now->index >= 0 && now->index != idx && ispal(str, i, str.size()-1)) {
                res.push_back({idx,now->index});
            }
            now = now->next[str[i]-'a'];
            if (!now) {
                return;
            }
        }
        for (auto &id: now->list) {
            if (idx == id) {
                continue;
            }
            res.push_back({idx,id});
        }
    }
    TNode *root;
    bool ispal(string &str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }
};
