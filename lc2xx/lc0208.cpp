//--- Q: 208. Implement Trie (Prefix Tree)

//--- method 1: trie tree data structure
class TrieNode
{
public:
    TrieNode *next[26];
    bool isWord;
    TrieNode()
    {
        memset(next, NULL, sizeof(TrieNode *)*26);
        isWord = false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *now = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int idx = word[i] - 'a';
            if (!now->next[idx])
                now->next[idx] = new TrieNode();
            now = now->next[idx];
        }
        now->isWord = true;            
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *now = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int idx = word[i] - 'a';
            if (!now->next[idx])
                return false;
            now = now->next[idx];
        }
        return (now->isWord) ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *now = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            int idx = prefix[i] - 'a';
            if (!now->next[idx])
                return false;
            now = now->next[idx];
        }
        return true;
    }

private:
   TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */