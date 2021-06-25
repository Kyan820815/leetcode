//--- Q: 224. Basic Calculator

//--- method 1: dfs recurision
class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        return dfs(idx, s);
    }
    int dfs(int &idx, string &s) {
        int total = 0, cur = 0;
        char lastop = '+';
        while (idx < s.size()) {
            if (s[idx] == ' ') {
                ++idx;
                continue;
            }
            if (s[idx] == '(') {
                ++idx;
                cur = dfs(idx, s);
            } else if (s[idx] == ')') {
                ++idx;
                total = count(lastop, cur, total);
                return total;
            } else if (s[idx] == '+' || s[idx] == '-') {
                total = count(lastop, cur, total);
                lastop = s[idx++];
                cur = 0;                
            } else {
                cur = cur*10+(s[idx++]-'0');
            }
        }
        return count(lastop, cur, total);
    }
    int count(char lastop, int cur, int total) {
        if (lastop == '-') {
            cur *= -1;
        }
        total += cur;
        return total;
    }
};