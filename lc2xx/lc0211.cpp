//--- Q: 211. Design Add and Search Words Data Structure

//--- method 1: trie tree
class TNode {
public:
    TNode() {
        memset(next, NULL, 26*sizeof(TNode *));
        isend = false;
    }
    
    TNode *next[26];
    bool isend;
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TNode();
    }
    
    void insert(string &word) {
        TNode *now = root;
        for (auto &c: word) {
            if (!now->next[c-'a']) {
                now->next[c-'a'] = new TNode();
            }
            now = now->next[c-'a'];
        }
        now->isend = true;
    }

    bool searchW(string &word, int idx, TNode *now) {
        if (!now) {
            return false;
        }
        if (idx == word.size()) {
            return now->isend;
        }
        if (word[idx] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (searchW(word, idx+1, now->next[i])) {
                    return true;
                }
            }
        } else {
            return searchW(word, idx+1, now->next[word[idx]-'a']);
        }
        return false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchW(word, 0, root);
    }
    TNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */