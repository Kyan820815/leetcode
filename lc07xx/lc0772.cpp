//--- Q: 772. Basic Calculator III

//--- method 1: recursion + stack
class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        return dfs(idx, s);
    }
    int dfs(int &idx, string &s) {
        char lastop = '+';
        int cur = 0;
        vector<int> sk;
        while (idx < s.size()) {
            if (s[idx] == '(') {
                ++idx;
                cur = dfs(idx, s);
            } else if (s[idx] == ')') {
                ++idx;
                count(cur, lastop, sk);
                return pop(sk);
            } else if (isdigit(s[idx])) {
                cur = cur * 10 + (s[idx++]-'0');
            } else {
                count(cur, lastop, sk);
                cur = 0;
                lastop = s[idx++];
            }
        }
        count(cur, lastop, sk);
        return pop(sk);
    }
    int pop(vector<int> &sk) {
        int total = 0;
        while (sk.size()) {
            total += sk.back();
            sk.pop_back();
        }
        return total;
    }
    void count(int cur, char lastop, vector<int> &sk) {
        if (lastop == '+') {
            sk.push_back(cur);
        } else if (lastop == '-') {
            sk.push_back(-cur);
        } else if (lastop == '*') {
            sk.back() *= cur;
        } else {
            sk.back() /= cur;
        }
    }
};