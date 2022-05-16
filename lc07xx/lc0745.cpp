//--- Q: 0745. Prefix and Suffix Search

//--- method 1: one trie
class TNode {
public:
    TNode() {
        next.resize(27, nullptr);
    }
    vector<TNode *> next;
    int idx;
};

class WordFilter {
public:
    TNode *root;
    
    void insert(string &word, int idx, int start) {
        int n = word.size();
        auto now = root;
        for (int i = start; i < 2*n; ++i) {
            if (!now->next[word[i%n]-'a']) {
                now->next[word[i%n]-'a'] = new TNode();
            }
            now = now->next[word[i%n]-'a'];
            now->idx = idx;
        }
    }
    
    int search(string &word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                return -1;
            }
            now = now->next[ch-'a'];
        }
        return now->idx;
    }
    
    WordFilter(vector<string>& words) {
        root = new TNode();
        for (int i = 0; i < words.size(); ++i) {
            string comp = "{" + words[i];
            for (int j = 1; j < comp.size(); ++j) {
                insert(comp, i, j);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + "{" + prefix;
        return search(word);
    }
};

//--- method 2: two trie


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */