//--- Q: 1804. Implement Trie II (Prefix Tree)

//--- method 1:
class TNode {
public:
    TNode() {
        next.resize(26, nullptr);
        cntend = cntmid = 0;
    }
    int cntend, cntmid;
    vector<TNode *> next;
};
class Trie {
public:
    TNode *root;
    Trie() {
        root = new TNode();
    }
    
    void insert(string word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
            ++now->cntmid;
        }
        ++now->cntend;
    }
    
    int countWordsEqualTo(string word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                return 0;
            }
            now = now->next[ch-'a'];
        }
        return now->cntend;
    }
    
    int countWordsStartingWith(string prefix) {
        auto now = root;
        for (auto &ch: prefix) {
            if (!now->next[ch-'a']) {
                return 0;
            }
            now = now->next[ch-'a'];
        }
        return now->cntmid;        
    }
    
    void erase(string word) {
        auto now = root;
        for (auto &ch: word) {
            now = now->next[ch-'a'];
            --now->cntmid;
        }
        --now->cntend;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */