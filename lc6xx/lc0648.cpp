//--- Q: 648. Replace Words

//--- method 1: string operation
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end());
        vector<vector<string>> cnt(26);
        istringstream ii(sentence);
        string str, res = "";
        for (auto &wd: dictionary) {
            cnt[wd[0]-'a'].push_back(wd);
        }
        while (ii >> str) {
            string newwd = str;
            for (auto &wd: cnt[str[0]-'a']) {
                if (str.substr(0, wd.size()) == wd) {
                    newwd = wd;
                    break;
                }
            }
            res += newwd + " ";
        }
        res.pop_back();
        return res;
    }
};

//--- method 2: trie tree
class Solution {
public:

    class TrieNode
    {
    public:
        TrieNode *node[26];
        bool isPrefix;
        TrieNode()
        {
            memset(node, NULL, sizeof(TrieNode *)*26);
            isPrefix = false;
        }
    private:
       
    };

    class trietree
    {
    public:
        trietree() {
            root = new TrieNode();
        }
        
        /** Inserts a prefix into the trie. */
        void insert(string &word) {
            TrieNode *now = root;
            for (int i = 0; i < word.size(); ++i)
            {
                if (!now->node[word[i] - 'a'])
                    now->node[word[i] - 'a'] = new TrieNode();
                now = now->node[word[i] - 'a'];
            }
            now->isPrefix = true;
        }
        
        /** Returns if the prefix of word is in the trie. */
        void search(string &word, string &out) {
            TrieNode *now = root;
            for (int i = 0; i < word.size(); ++i)
            {
                if (now->node[word[i] - 'a'])
                {
                    now = now->node[word[i] - 'a'];
                    out += word[i];
                    if (now->isPrefix)
                        return;
                }
                else
                {
                    out = word;
                    return;
                }
            }
        }
        
    private:
        TrieNode *root;
    };

    string replaceWords(vector<string>& dict, string sentence) {
        trietree *tree = new trietree();
        istringstream stream(sentence);
        string res = "", s;

        for (int i = 0; i < dict.size(); ++i)
            tree->insert(dict[i]);

        while (stream >> s)
        {
            string out = "";
            tree->search(s, out);
            res += out + ' ';
        }
        res.pop_back();
        return res;
    }
};

