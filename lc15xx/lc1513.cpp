//--- Q: 1513. Number of Substrings With Only 1s

//--- method 1: count 1
class Solution {
public:
    int numSub(string s) {
        int n = s.size(), cnt = 0, res = 0, mod = 1e9+7;
        for (int i = 0; i < n; ++i) {
            cnt = s[i] == '1' ? cnt+1 : 0;
            res = (res+cnt) % mod;
        }
        return res;
    }
};