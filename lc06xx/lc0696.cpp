//--- Q: 0696. Count Binary Substrings

//--- method 1: two pointer, count same characters
class Solution {
public:
    int countBinarySubstrings(string s) {
        int lcnt = 0, ccnt = 1, res = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[i-1]) {
                res += min(lcnt, ccnt);
                lcnt = ccnt;
                ccnt = 0;
            }
            ++ccnt;
        }
        return res;
    }
};