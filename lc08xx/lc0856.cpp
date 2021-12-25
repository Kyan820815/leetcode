//--- Q: 0856. Score of Parentheses

//--- method 1: O(1) space, better
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size(), depth = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++depth;
                if (s[i+1] == ')') {
                    res += (1 << (depth-1));
                }
            } else {
                --depth;
            }
        }
        return res;
    }
};