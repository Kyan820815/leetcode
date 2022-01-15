//--- Q: 1021. Remove Outermost Parentheses

//--- method 1: use counter and skip outer parantheness
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int left = 0;
        for (auto &ch: s) {
            if (ch == '(') {
                if (++left > 1) {
                    res += ch;
                }
            } else if (--left > 0) {
                res += ch;
            }
        }
        return res;
    }
};