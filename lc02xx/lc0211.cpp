//--- Q: 0211. Design Add and Search Words Data Structure

//--- method 1: trie tree
class TNode {
public:
    TNode() {
        isend = false;
        next.resize(26, NULL);
    }
    bool isend;
    vector<TNode *> next;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TNode();
    }
    
    void addWord(string word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
        }
        now->isend = true;
    }
    
    bool search(string word) {
        return findWord(0, word, root);
    }
    bool findWord(int idx, string &word, TNode *now) {
        for (int i = idx; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (auto &next_node: now->next) {
                    if (next_node && findWord(i+1, word, next_node)) {
                        return true;
                    }
                }
                return false;
            } else {
                now = now->next[word[i]-'a'];
            }
            if (!now) {
                return false;
            }
        }
        return now->isend;
    }
    TNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */