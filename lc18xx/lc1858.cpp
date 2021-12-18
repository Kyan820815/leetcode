//--- Q: 1858. Longest Word With All Prefixes

//--- method 1: trie tree
class TNode {
public:
    TNode() {
        end = false;
        next.resize(26, nullptr);
    }
    vector<TNode *> next;
    bool end;
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
        for (auto &word: words) {
            insert(word);
        }
        string res = "";
        for (auto &word: words) {
            if (search(word)) {
                if (word.size() > res.size()) {
                    res = word;
                } else if (word.size() == res.size() && word < res) {
                    res = word;
                }
            }
        }
        return res;
    }
};

//--- method 2: sort and find substring
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        string res = "";
        unordered_set<string> set;
        for (auto &word: words) {
            string tmp = "";
            int i;
            set.insert(word);
            for (i = 0; i < word.size(); ++i) {
                tmp += word[i];
                if (set.find(tmp) == set.end()) {
                    break;
                }
            }
            if (i == word.size()) {
                if (res.size() < word.size()) {
                    res = word;
                } else if (res.size() == word.size() && res > word) {
                    res = word;
                }
            }
        }
        return res;
    }
};
