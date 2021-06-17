//--- Q: 696. Count Binary Substrings

//--- method 1: two pointer, count same characters
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, lastcnt = 0, cnt = 1;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size() || s[i] != s[i-1]) {
                res += min(cnt, lastcnt);
                lastcnt = cnt;
                cnt = 0;
            }
            ++cnt;
        }
        return res;
    }
};

//--- method 2: my version, not good
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] != s[i+1]) {
                int left = i, right = i+1;
                while (left >= 0 && right < s.size() && s[left] == s[i] && s[right] == s[i+1]) {
                    --left, ++right;
                    ++res;
                }
            }
        }
        return res;
    }
};