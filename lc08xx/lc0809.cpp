//--- Q: 809. Expressive Words

//--- method 1: trie tree
class Node {
public:
    Node(int l) {
        isword = false;
        len = l;
        next.resize(26);
    }
    bool isword;
    vector<Node *> next;
    int len;
};

class Tree {
public:
    Tree() {
        root = new Node(0);
    }
    void insert(string &s, vector<int> &cnt) {
        Node *now = root;
        for (int i = 0; i < s.size(); ++i) {
            if (!now->next[s[i]-'a']) {
                now->next[s[i]-'a'] = new Node(cnt[i]);
            }
            now = now->next[s[i]-'a'];
        }
        now->isword = true;
    }
    bool check(string &s, vector<int> &cnt) {
        Node *now = root;
        for (int i = 0; i < s.size(); ++i) {
            if (!now->next[s[i]-'a'])
                return false;
            now = now->next[s[i]-'a'];
            if (now->len < 3 && now->len != cnt[i] || now->len < cnt[i])
                return false;
        }
        return now->isword;
    }
    Node *root;
};

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        string newS;
        vector<int> cnt;
        
        transform(S, newS, cnt);
        
        Tree *trie = new Tree();
        trie->insert(newS, cnt);
        for (int i = 0; i < words.size(); ++i) {
            transform(words[i], newS, cnt);
            if (trie->check(newS, cnt))
                ++res;
        }
        return res;
    }
    void transform(string &S, string &newS, vector<int> &cnt) {
        int nowC = 1;
        newS = "";
        cnt.clear();
        for (int i = 0; i < S.size()-1; ++i) {
            if (S[i] != S[i+1]) {
                newS.push_back(S[i]);
                cnt.push_back(nowC);
                nowC = 1;
            } else
                ++nowC;
        }
        newS.push_back(S.back());
        cnt.push_back(nowC);
    }
};

//--- method 2: double pointer
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (check(S, words[i]))
                ++res;
        }
        return res;
    }
    bool check(string s, string w) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == w[j])
                ++j;
            else if (i > 0 && i < s.size()-1 && s[i] == s[i-1] && s[i] == s[i+1]);
            else if (i > 1 && s[i] == s[i-1] && s[i-1] == s[i-2]);
            else
                return false;
        }
        return j == w.size();
    }
};