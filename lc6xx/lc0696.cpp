//--- Q: 696. Count Binary Substrings

//--- method 1: two pointer, count same characters
class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, cur = 1, pre = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i == s.size()-1 || s[i] != s[i+1]) {
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            } else {
                ++cur;
            }
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