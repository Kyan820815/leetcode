//--- Q: 0224. Basic Calculator

//--- method 1: dfs recurision
class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        return dfs(idx, s);
    }
    int dfs(int &idx, string &s) {
        int cur_sum = 0, total = 0;
        char lastop = '+';
        while (idx < s.size()) {
            if (s[idx] == ' ') {
                ++idx;
                continue;
            }
            if (s[idx] == '(') {
                ++idx;
                cur_sum = dfs(idx, s);
            } else if (s[idx] == ')') {
                ++idx;
                return combine(total, cur_sum, lastop);
            } else if (isdigit(s[idx])) {
                cur_sum = cur_sum*10 + (s[idx++]-'0');
            } else {
                total = combine(total, cur_sum, lastop);
                cur_sum = 0;
                lastop = s[idx++];
            }
        }
        return combine(total, cur_sum, lastop);
    }
    int combine(int total, int cur_sum, char lastop) {
        if (lastop == '+') {
            return total += cur_sum; 
        } else {
            return total -= cur_sum;
        }
    }
};