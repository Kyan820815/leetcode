//--- Q: 1190. Reverse Substrings Between Each Pair of Parentheses

//--- method 1: O(n^2) time
class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> sk = {""};
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push_back("");
            } else if (s[i] == ')') {
                reverse(sk.back().begin(), sk.back().end());
                sk[sk.size()-2] += sk.back();
                sk.pop_back();
            } else {
                sk.back().push_back(s[i]);
            }
        }
        return sk.back();
    }
};

//--- method 2: O(n) time
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> pair(s.size()), sk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push_back(i);
            } else if (s[i] == ')') {
                pair[sk.back()] = i;
                pair[i] = sk.back();
                sk.pop_back();
            }
        }
        string res = "";
        for (int i = 0, d = 1; i < s.size(); i+=d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d *= -1;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};