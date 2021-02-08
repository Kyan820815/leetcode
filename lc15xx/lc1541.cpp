//--- Q: 1541. Minimum Insertions to Balance a Parentheses String

//--- method 1: stack count
class Solution {
public:
    int minInsertions(string s) {
        int res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else {
                if (i < s.size()-1 && s[i+1] == ')') {
                    ++i;
                } else {
                    ++res;
                }
                if (--left < 0) {
                    ++res;
                    left = 0;
                }
            }
        }
        return res + left*2;
    }
};