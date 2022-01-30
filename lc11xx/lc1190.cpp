//--- Q: 1190. Reverse Substrings Between Each Pair of Parentheses

//--- method 1: O(n^2) time
class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> sk;
        string cur = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push_back(cur);
                cur = "";
            } else if (s[i] == ')') {
                reverse(cur.begin(), cur.end());
                cur = sk.back()+cur;
                sk.pop_back();
            } else {
                cur += s[i];
            }
        }
        return cur;
    }
};

//--- method 2: O(n) time
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> sk, pair(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push_back(i);
            } else if (s[i] == ')') {
                pair[i] = sk.back();
                pair[sk.back()] = i;
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