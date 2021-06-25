//--- Q: 0678. Valid Parenthesis String

//--- method 1: two pointer for lower bound and upper bound
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (auto &ch: s) {
            if (ch == '(') {
                ++low;
                ++high;
            } else if (ch == ')') {
                if (low > 0) {
                    --low;
                }
                --high;
            } else {
                if (low > 0) {
                    --low;
                }
                ++high;
            }
            if (high < 0) {
                return false;
            }
        }
        return !low;
    }
};