//--- Q: 0648. Replace Words

//--- method 1: trie tree
class TNode {
public:
    TNode () {
        isend = false;
        next.resize(26, nullptr);
    }
    bool isend;
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
            if (now->isend) {
                return;
            }
        }
        now->isend = true;
    }
    string search(string &word) {
        string res = "";
        auto now = root;
        for (auto &ch: word) {
            res += ch;
            if (!now->next[ch-'a']) {
                break;
            }
            now = now->next[ch-'a'];
            if (now->isend) {
                return res;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TNode();
        for (auto &word: dictionary) {
            insert(word);
        }
        istringstream ss(sentence);
        string word, res = "";
        while (ss >> word) {
            res += search(word) + " ";
        }
        res.pop_back();
        return res;
    }
    TNode *root;
};

//--- method 2: string operation
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<set<string>> cnt(26);
        for (auto &word: dictionary) {
            cnt[word[0]-'a'].insert(word);
        }
        istringstream ss(sentence);
        string word, res = "";
        while (ss >> word) {
            string simplfied_wd = word;
            for (auto &candidate: cnt[word[0]-'a']) {
                if (word.substr(0, candidate.size()) == candidate) {
                    simplfied_wd = candidate;
                    break;
                }
            }
            res += simplfied_wd + " ";
        }
        res.pop_back();
        return res;
    }
};