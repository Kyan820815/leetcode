//--- Q: 0758. Bold Words in String

//--- method 1: trie tree
class TNode {
public:
    TNode() {
        next.resize(128, nullptr);
        end = false;
    }
    vector<TNode *> next;
    bool end;
};
class Solution {
public:
    TNode *root;
    void insert(string &word) {
        auto now = root;
        for (auto &ch: word) {
            if (!now->next[ch]) {
                now->next[ch] = new TNode();
            }
            now = now->next[ch];
        }
        now->end = true;
    }
    int search(string &word, int idx) {
        auto now = root;
        int last = -1;
        for (int i = idx; i < word.size(); ++i) {
            if (!now->next[word[i]]) {
                return last;
            }
            now = now->next[word[i]];
            if (now->end) {
                last = i;
            }
        }
        return last;
    }
    string boldWords(vector<string>& words, string s) {
        root = new TNode();
        for (auto &word: words) {
            insert(word);
        }
        int n = s.size();
        vector<int> rtn;
        for (int i = 0; i < n; ++i) {
            rtn.push_back(search(s, i));
        }
        rtn.push_back(-1);
        string res = "";
        int i = 0, first = 0, last = -1;
        while (i < n) {
            if (i > last) {
                if (rtn[i] == -1) {
                    if (last != -1) {
                        res += "<b>" + s.substr(first, last-first+1) + "</b>";
                    }
                    res += s[i];
                    first = i;
                } else if (last == -1) {
                    first = i;
                }
                last = rtn[i];
            } else {
                last = max(last, rtn[i]);
            }
            ++i;
        }
        if (last != -1) {
            res += "<b>" + s.substr(first, last-first+1) + "</b>";
        }
        return res;
    }
};

//--- method 2: find interval
class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        vector<int> arr;
        for (int i = 0; i < s.size(); ++i) {
            int end = -1;
            for (auto &word: words) {
                if (s.find(word, i) == i) {
                    end = max(end, i+(int)word.size()-1);
                }
            }
            arr.push_back(end);
        }
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (arr[i] == -1) {
                res += s[i];
            } else {
                int first = i;
                int last = arr[i++];
                while (i < last || i < s.size()) {
                    if (i > last && arr[i] == -1) {
                        break;
                    }
                    last = max(last, arr[i++]);
                }
                res += "<b>" + s.substr(first, last-first+1) + "</b>";
                --i;
            }
        }
        return res;
    }
};

//--- method 3: boolean array
class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        vector<int> arr(s.size(), 0);
        for (auto &word: words) {
            int start = -1;
            while (1) {
                int start = s.find(word, start+1);
                if (start == -1) {
                    break;
                }
                for (int i = start; i < start+word.size(); ++i) {
                    arr[i] = 1;
                }
            }
        }
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (!arr[i]) {
                res += s[i];
            } else {
                res += "<b>";
                while (i < s.size() && arr[i]) {
                    res += s[i++];
                }
                res += "</b>";
                --i;
            }
        }
        return res;
    }
};