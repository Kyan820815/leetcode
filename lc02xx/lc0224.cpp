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

//--- method 2: stack iteration
class Solution {
public:
    int calculate(string s) {
        vector<pair<int,char>> gsk;
        char lastop = '+';
        int total = 0, val = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            if (s[i] == '(') {
                gsk.push_back({total,lastop});
                total = 0;
                lastop = '+';
                ++i;
            } else if (s[i] == ')') {
                total = put(val, total, lastop);
                val = total, lastop = gsk.back().second;
                total = gsk.back().first;
                gsk.pop_back();
                ++i;
            } else if (isdigit(s[i])) {
                val = val *10 + (s[i++]-'0');
            } else {
                total = put(val, total, lastop);
                val = 0;
                lastop = s[i++];
            }
        }
        total = put(val, total, lastop);
        return total;
    }
    int put(int val, int total, char &lastop) {
        if (lastop == '+') {
            total += val;
        } else {
            total -= val;
        }
        return total;
    }
};