//--- Q: 0767. Reorganize String

//--- method 1: greedy method, clean code
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        for (auto &ch: s) {
            ++cnt[ch-'a'];
        }
        int maxcnt = 0;
        char maxch;
        for (int i = 0; i < 26; ++i) {
            if (maxcnt < cnt[i]) {
                maxcnt = cnt[i];
                maxch = i+'a';
            }
        }
        if (maxcnt*2 > s.size()+1) {
            return "";
        }
        cnt[maxch-'a'] = 0;
        int cur = 0;
        string res(s.size(), '.');
        while (maxcnt--) {
            res[cur] = maxch;
            cur += 2;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (cur >= s.size()) {
                    cur = 1;
                }
                res[cur] = i+'a';
                cur += 2;
            }
        }
        return res;
    }
};