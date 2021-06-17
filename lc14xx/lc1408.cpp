//--- Q: 1408. String Matching in an Array

//--- method 1: prefix tree
class TNode {
public:
    TNode () {
        end = 0;
        next.resize(26, NULL);
    }
    vector<TNode *> next;
    int end;
};
class Solution {
public:
    unordered_set<string> res;
    TNode *root;
    vector<string> stringMatching(vector<string>& words) {
        root = new TNode();
        for (auto &word: words) {
            for (int i = word.size()-1; i >= 0; --i) {
                string tmp = word.substr(i);
                insert(tmp);
            }
        }
        for (auto &word: words) {
            search(word);
        }
        return vector<string>(res.begin(), res.end());
    }
    void insert(string &word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch-'a']) {
                now->next[ch-'a'] = new TNode();
            }
            now = now->next[ch-'a'];
            ++now->end;
        }
    }
    void search(string &word) {
        auto now = root;
        for (auto &ch: word) {
            now = now->next[ch-'a'];
        }
        if (now->end > 1) {
            res.insert(word);
        }
    }
};

//--- method 2: brute force
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> res;
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (words[i].find(words[j]) != string::npos) {
                    res.insert(words[j]);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};