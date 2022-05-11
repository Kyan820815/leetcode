//--- Q: 2067. Number of Equal Count Substrings

//--- method 1: sliding window for 1 ~ u unique characters
class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int usize = unordered_set(s.begin(), s.end()).size(), res = 0;
        for (int u = 1; u <= usize; ++u) {
            vector<int> cnt(26, 0);
            int len = u*count, ch = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (i >= len) {
                    if (--cnt[s[i-len]-'a'] == count-1) {
                        --ch;
                    }
                }
                if (++cnt[s[i]-'a'] == count) {
                    ++ch;
                }
                res += ch == u;
            }
        }
        return res;
    }
};