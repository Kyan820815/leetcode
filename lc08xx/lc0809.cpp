//--- Q: 0809. Expressive Words

//--- method 1: double pointer
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (auto &word: words) {
            res += valid(s, word);
        }
        return res;
    }
    int valid(string &s, string &word) {
        int i = 0, j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == word[j]) {
                ++j; 
            } else if (i && i < s.size()-1 && s[i] == s[i-1] && s[i] == s[i+1]);
            else if (i > 1 && s[i] == s[i-1] && s[i-1] == s[i-2]);
            else {
                return 0;
            }
        }
        return j == word.size();
    }
};

//--- method 2: trie tree
class TNode {
public:
    TNode() {
        next.resize(26, nullptr);
        len = end = 0;
    }
    vector<TNode *> next;
    int len, end;
};
class Solution {
public:
    TNode *root;
    int expressiveWords(string s, vector<string>& words) {
        root = new TNode();
        vector<pair<char,int>> pks;
        int cnt = 1;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[i-1]) {
                pks.push_back({s[i-1],cnt});
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        insert(pks);
        int res = 0;
        for (auto &word: words) {
            vector<pair<char,int>> pkword;
            cnt = 1;
            for (int i = 1; i <= word.size(); ++i) {
                if (i == word.size() || word[i] != word[i-1]) {
                    pkword.push_back({word[i-1],cnt});
                    cnt = 1;
                } else {
                    ++cnt;
                }
            }
            res += search(pkword);
        }
        return res;
    }
    void insert(vector<pair<char,int>> &s) {
        auto now = root;
        for (auto &p: s) {
            now->next[p.first-'a'] = new TNode();
            now = now->next[p.first-'a'];
            now->len = p.second;
        }
        now->end = 1;
    }
    bool search(vector<pair<char,int>> &s) {
        auto now = root;
        for (auto &p: s) {
            if (!now->next[p.first-'a']) {
                return false;
            }
            now = now->next[p.first-'a'];
            if (now->len < 3 && now->len != p.second || now->len < p.second) {
                return false;
            }
        }
        return now->end;
    }
};