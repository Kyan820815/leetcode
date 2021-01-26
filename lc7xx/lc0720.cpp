//--- Q: 720. Longest Word in Dictionary

//--- method 1: sort
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> set;
        string res = "";
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() == 1 || set.find(words[i].substr(0, words[i].size()-1)) != set.end()) {
                set.insert(words[i]);
                res = words[i].size() > res.size() ? words[i] : res;
            }
        }
        return res;
    }
};

//--- method 2: trie tree
class TrieNode {
public:
    TrieNode() {
        isend = false;
        memset(next, 0, 26*sizeof(TrieNode *));
    }
    bool isend;
    TrieNode *next[26];
};

class TrieTree {
public:
    TrieTree() {
        root = new TrieNode();
    }
    void insert(string &now) {
        TrieNode *node = root;
        for (int i = 0; i < now.size(); ++i) {
            if (!node->next[now[i]-'a']) {
                node->next[now[i]-'a'] = new TrieNode();
            }
            node = node->next[now[i]-'a'];
        }
        node->isend = true;
    }
    TrieNode *root;
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        TrieTree *tree = new TrieTree();
        string res = "";
        for (int i = 0; i < words.size(); ++i) {
            tree->insert(words[i]);
        }
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() == 1) {
                string str(1, words[i][0]);
                dfs(tree->root->next[words[i][0]-'a'], res, str);
            }
        }
        return res;
    }
    void dfs(TrieNode *now, string &res, string &str) {
        if (now->isend) {
            if (str.size() > res.size()) {
                res = str;
            } else if (str.size() == res.size()) {
                res = min(res, str);
            }
            for (int i = 0; i < 26; ++i) {
                if (now->next[i]) {
                    str.push_back(i+'a');
                    dfs(now->next[i], res, str);
                    str.pop_back();
                }
            }
        }
    }
};