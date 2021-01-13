//--- Q: 020. Valid Parentheses

//--- method 1: stack
class Solution {
public:
    bool isValid(string s) {
        int left = 0;
        vector<char> sk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sk.push_back(s[i]);
            } else if (sk.size() && (s[i]==')' && sk.back() == '(' || s[i]==']' && sk.back() == '[' || s[i]=='}' && sk.back() == '{')) {
                sk.pop_back();
            } else {
                return false;
            }
        }
        return !sk.size();
    }
};