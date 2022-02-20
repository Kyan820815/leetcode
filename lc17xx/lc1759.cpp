//--- Q: 1759. Count Number of Homogenous Substrings

//--- method 1: math formula
class Solution {
public:
    using ll = long long;
    int countHomogenous(string s) {
        int n = s.size(), last = 0, res = 0, mod = 1e9+7;
        for (int i = 1; i <= n; ++i) {
            if (i == n || s[i] != s[i-1]) {
                int len = i-last;
                ll cnt = (ll)(1+len)*len/2;
                res = (res + cnt) % mod;
                last = i;
            }
        }
        return res;
    }
};

//--- method 2: compare with last
class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), res = 1, mod = 1e9+7, cnt = 1;
        for (int i = 1; i < n; ++i) {
            cnt = s[i] != s[i-1] ? 1 : cnt+1;
            res = (res + cnt) % mod;
        }
        return res;
    }
};