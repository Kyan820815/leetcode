//--- Q: 0921. Minimum Add to Make Parentheses Valid

//--- method 1: stack operation
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;
        vector<char> sk;
        for (auto &ch: s) {
            if (ch == '(') {
                sk.push_back(ch);
            } else {
                if (sk.size()) {
                    sk.pop_back();
                } else {
                    ++res;
                }
            }
        }
        return res + sk.size();
    }
};

//--- method 2: O(1) space
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, left = 0;
        for (auto &ch: s) {
            if (ch == '(') {
                ++left;
            } else {
                if (--left < 0) {
                    left = 0;
                    ++res;
                }
            }
        }
        return res + left;
    }
};