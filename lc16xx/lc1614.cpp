//--- Q: 1614. Maximum Nesting Depth of the Parentheses

//--- method 1: linear search
class Solution {
public:
    int maxDepth(string s) {
        int left = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
                res = max(res, left);
            } else if (s[i] == ')') {
                --left;
            }
        }
        return res;
    }
};