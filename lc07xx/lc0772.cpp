//--- Q: 0772. Basic Calculator III

//--- method 1: recursion + stack
class Solution {
public:
    int calculate(string s) {
        int idx = 0;
        return dfs(idx, s);
    }
    int dfs(int &idx, string &s) {
        vector<int> sk;
        char lastop = '+';
        int sum = 0, val = 0;
        while (idx < s.size()) {
            if (s[idx] == '(') {
                ++idx;
                val = dfs(idx, s);
            } else if (s[idx] == ')') {
                ++idx;
                push(sk, lastop, val);
                return combine(sk);
            } else if (isdigit(s[idx])) {
                val = val*10 + s[idx++]-'0';
            } else {
                push(sk, lastop, val);
                lastop = s[idx++];
                val = 0;
            }
        }
        push(sk, lastop, val);
        return combine(sk);
    }
    void push(vector<int> &sk, char op, int val) {
        if (op == '+') {
            sk.push_back(val);
        } else if (op == '-') {
            sk.push_back(-val);
        } else if (op == '*') {
            sk.back() *= val;
        } else {
            sk.back() /= val;
        }
    }
    int combine(vector<int> &sk) {
        int sum = 0;
        for (auto &val: sk) {
            sum += val;
        }
        return sum;
    }
};

//--- method 2: two stack iteration
class Solution {
public:
    int calculate(string s) {
        vector<int> cur;
        vector<pair<vector<int>, char>> cache;
        char lastop = '+';
        int idx = 0, val = 0;
        while (idx < s.size()) {
            if (s[idx] == '(') {
                ++idx;
                cache.push_back({cur,lastop});
                lastop = '+';
                cur.clear();
            } else if (s[idx] == ')') {
                ++idx;
                push(cur, lastop, val);
                val = combine(cur);
                cur = cache.back().first;
                lastop = cache.back().second;
                cache.pop_back();
            } else if (isdigit(s[idx])) {
                val = val*10 + s[idx++]-'0';
            } else {
                push(cur, lastop, val);
                lastop = s[idx++];
                val = 0;
            }
        }
        push(cur, lastop, val);
        return combine(cur);
    }
    void push(vector<int> &sk, char op, int val) {
        if (op == '+') {
            sk.push_back(val);
        } else if (op == '-') {
            sk.push_back(-val);
        } else if (op == '*') {
            sk.back() *= val;
        } else {
            sk.back() /= val;
        }
    }
    int combine(vector<int> &sk) {
        int sum = 0;
        for (auto &val: sk) {
            sum += val;
        }
        return sum;
    }
};