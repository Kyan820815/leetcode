//--- Q: 1446. Consecutive Characters

//--- method 1: count length
class Solution {
public:
    int maxPower(string s) {
        int n = s.size(), res = 0, last = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n || s[i] != s[i-1]) {
                res = max(res, i-1-last+1);
                last = i;
            }
        }
        return res;
    }
};