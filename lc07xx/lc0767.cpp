//--- Q: 767. Reorganize String

//--- method 1-1: greedy method
class Solution {
public:
    string reorganizeString(string S) {
        vector<vector<char>> cnt(S.size()+1);
        vector<int> ch(26, 0);
        string res(S.size(), '0');
        int start = 0, now = 0, kind = 0, maxcnt = 0;
        for (int i = 0; i < S.size(); ++i) {
            ++ch[S[i]-'a'];
            if (maxcnt < ch[S[i]-'a']) {
                maxcnt = ch[S[i]-'a'];
                kind = 1;
            } else if (maxcnt == ch[S[i]-'a']) {
                ++kind;
            }
        }
        if ((maxcnt-1)*2 + kind > S.size())
            return "";
        for (int i = 0; i < 26; ++i) {
            cnt[ch[i]].push_back(i+'a');
        }
        int k = 0;
        for (int i = S.size(); i >= 1; --i) {
            if (cnt[i].size()) {
                for (int j = 0; j < cnt[i].size(); ++j) {
                    int t = 0;
                    while (t < i) {
                        if (k >= S.size()) {
                            ++start;
                            k = start;
                        }
                        res[k] = cnt[i][j];
                        ++t;
                        k += 2;
                    }
                }
            }
        }
        return res;
    }
};

//--- method 1-2: greedy method, clean code
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> ch(26, 0);
        string res(S.size(), '0');
        int kind = 0, maxcnt = 0;
        for (int i = 0; i < S.size(); ++i) {
            ++ch[S[i]-'a'];
            if (maxcnt < ch[S[i]-'a']) {
                maxcnt = ch[S[i]-'a'];
                kind = S[i]-'a';
            }
        }
        if (maxcnt*2-1 > S.size()) {
            return "";
        }
        // fill max letter first
        int idx = 0;
        while (ch[kind]) {
            res[idx] = kind + 'a';
            --ch[kind];
            idx += 2;
        }
        for (int i = 0; i < 26; ++i) {
            while (ch[i]) {
                if (idx >= S.size()) {
                    idx = 1;
                }
                res[idx] = i + 'a';
                --ch[i];
                idx += 2;
            }
        }
        return res;
    }
};

