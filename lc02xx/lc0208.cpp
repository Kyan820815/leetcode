//--- Q: 0208. Implement Trie (Prefix Tree)

//--- method 1: trie tree data structure
class TNode {
public:
    TNode() {
        isend = false;
        next.resize(26, nullptr);
    }
    bool isend;
    vector<TNode *> next;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
        }
        now->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto now = root;
        for (auto &ch: word) {
            now = now->next[ch-'a'];
            if (!now) {
                return false;
            }
        }
        return now->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto now = root;
        for (auto &ch: prefix) {
            now = now->next[ch-'a'];
            if (!now) {
                break;
            }
        }
        return now != nullptr;
    }
    TNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */