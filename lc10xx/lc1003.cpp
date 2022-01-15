//--- Q: 1003. Check If Word Is Valid After Substitutions

//--- method 1: stack operation
class Solution {
public:
    bool isValid(string s) {
        string sk = "";
        for (auto &ch: s) {
            if (ch == 'c') {
                if (sk.size() > 1 && sk[sk.size()-1] == 'b' && sk[sk.size()-2] == 'a') {
                    sk.pop_back();
                    sk.pop_back();
                } else {
                    return false;
                }
            } else {
                sk += ch;
            }
        }
        return sk == "";
    }
};

//--- method 2: simulation of stack
class Solution {
public:
    bool isValid(string s) {
        string sk = "";
        int idx = -1;
        for (auto &ch: s) {
            if (ch == 'c') {
                if (idx > 0 && s[idx] == 'b' && s[idx-1] == 'a') {
                    idx -= 2;
                } else {
                    return false;
                }
            } else {
                s[++idx] = ch;
            }
        }
        return idx == -1;
    }
};