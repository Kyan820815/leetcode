//--- Q: 0678. Valid Parenthesis String

//--- method 1: two pointer for lower bound and upper bound
class Solution {
public:
    bool checkValidString(string s) {
        int upper = 0, lower = 0;
        for (auto &ch: s) {
            if (ch == '(') {
                ++upper, ++lower;
            } else if (ch == ')') {
                --upper;
                if (--lower < 0) {
                    lower = 0;
                }
            } else {
                ++upper;
                if (--lower < 0) {
                    lower = 0;
                }
            }
            if (upper < 0) {
                return false;
            }
        }
        return lower == 0;
    }
};