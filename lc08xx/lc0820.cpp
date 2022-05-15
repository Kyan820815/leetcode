//--- Q: 0820. Short Encoding of Words

//--- method 1: trie
class TNode {
public:
    TNode() {
        next.resize(26, nullptr);
    }
    vector<TNode *> next;
};
class Solution {
public:
    TNode *root;
    int res = 0;
    vector<pair<TNode *, int>> leaves;
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        root = new TNode();
        for (auto &word: set) {
            insert(word);
        }
        for (auto &leaf: leaves) {
            if (last(leaf.first)) {
                res += leaf.second;
            }
        }
        return res;
    }
    void insert(string word) {
        auto now = root;
        for (int i = word.size()-1; i >= 0; --i) {
            if (!now->next[word[i]-'a']) {
                now->next[word[i]-'a'] = new TNode();
            }
            now = now->next[word[i]-'a'];
        }
        leaves.push_back({now, word.size()+1});
    }
    bool last(TNode *node) {
        for (auto &v: node->next) {
            if (v != nullptr) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: set erase
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> set(words.begin(), words.end());
        int res = 0;
        for (auto &word: set) {
            for (int i = 1; i < word.size(); ++i) {
                set.erase(word.substr(i));
            }
        }
        for (auto &word: set) {
            res += word.size()+1;
        }
        return res;
    }
};