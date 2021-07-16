//--- Q: 0336. Palindrome Pairs

//--- method 1: trie tree
class TNode {
public:    
    TNode() {
        index = -1;
        next.resize(26, nullptr);
    }
    int index;
    vector<int> index_list;
    vector<TNode *> next;
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new TNode();
        for (int i = 0; i < words.size(); ++i) {
            insert(i, words[i]);
        }
        for (int i = 0; i < words.size(); ++i) {
            search(i, words[i]);
        }
        return res;
    }
    void insert(int idx, string &s) {
        auto now = root;
        for (int i = s.size()-1; i >= 0; --i) {
            if (ispal(s, 0, i)) {
                now->index_list.push_back(idx);
            }
            if (!now->next[s[i]-'a']) {
                now->next[s[i]-'a'] = new TNode();
            }
            now = now->next[s[i]-'a'];
        }
        now->index = idx;
        now->index_list.push_back(idx);
    }
    void search(int idx, string &s) {
        auto now = root;
        for (int i = 0; i < s.size() && now; ++i) {
            if (now->index != -1 && now->index != idx && ispal(s, i, s.size()-1)) {
                res.push_back({idx, now->index});
            }
            now = now->next[s[i]-'a'];
        }
        if (!now) {
            return;
        }
        for (auto &pair_id: now->index_list) {
            if (pair_id != idx) {
                res.push_back({idx, pair_id});
            }
        }
    }
    bool ispal(string &s, int left, int right) {
        for (;left < right; ++left, --right) {
            if (s[left] != s[right]) {
                return false;
            }
        }
        return true;
    }
    TNode *root;
};