//--- Q: 1249. Minimum Remove to Make Valid Parentheses

//--- method 1: stack iteration
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> sk;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] =='(')
                sk.push(i);
            else if (s[i] == ')') {
                if (sk.size())
                    sk.pop();
                else
                    s[i] = '*';
            }
        }
        while(sk.size()) {
            s[sk.top()] = '*';
            sk.pop();
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*')
                res.push_back(s[i]);
        }
        return res;
    }
};