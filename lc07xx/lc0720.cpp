//--- Q: 0720. Longest Word in Dictionary

//--- method 1: trie tree
class TNode {
public:
    TNode() {
        next.resize(26, nullptr);
        end = false;
    }
    bool end;
    vector<TNode *> next;
};

class Solution {
public:
    void insert(string &word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
        }
        now->end = true;
    }
    bool search(string &word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                return false;
            }
            now = now->next[ch-'a'];
            if (!now->end) {
                return false;
            }
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        root = new TNode();
        string res = "";
        for (auto &word: words) {
            insert(word);
        }
        for (auto &word: words) {
            if (search(word)) {
                if (word.size() > res.size() || word.size() == res.size() && word < res) {
                    res = word;
                }
            }
        }
        return res;
    }
    TNode *root;
};

//--- method 2: sort
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> set = {""};
        string res = "";
        for (auto &word: words) {
            auto prev = word.substr(0,word.size()-1);
            if (set.find(prev) != set.end()) {
                set.insert(word);
                if (word.size() > res.size() || word.size() == res.size() && word < res) {
                    res = word;
                }
            }
        }
        return res;
    }
};