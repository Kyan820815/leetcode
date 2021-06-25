//--- Q: 301. Remove Invalid Parentheses

//--- method 1: remove right first then left, recursion
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(0, 0, s, {'(', ')'}, res);
        return res;
    }
    void dfs(int last_i, int last_j, string &now, vector<char> par, vector<string> &res) {
        int left = 0;
        for (int i = last_i; i < now.size(); ++i) {
            if (now[i] == par[0])
                ++left;
            else if (now[i] == par[1])
                --left;
            if (left < 0) {
                for (int j = last_j; j <= i; ++j) {
                	// --- delete every invalid paratheness and go recursion
                    if (now[j] == par[1] && (j == last_j || now[j] != now[j-1])) {
                        string next = now.substr(0, j) + now.substr(j+1);
                        dfs(i, j, next, par, res);
                    }
                }
                return;
            }
        }
        reverse(now.begin(), now.end());
        if (par[0] == '(')
            dfs(0, 0, now, {')', '('}, res);
        else
            res.push_back(now);
    }
};

//--- method 2: bfs
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> que;
        vector<string> res;
        unordered_set<string> set;
        que.push(s);
        int qsize = 1;
        bool find = false;
        while (que.size()) {
            for (int q = 0; q < qsize; ++q) {
                auto now = que.front();
                que.pop();
                if (isValid(now)) {
                    find = true;
                    res.push_back(now);
                }
                if (find)
                    continue;
                for (int i = 0; i < now.size(); ++i) {
                    if (now[i] != '(' && now[i] != ')')
                        continue;
                    string next = now.substr(0, i) + now.substr(i+1);
                    if (set.find(next) == set.end()) {
                        set.insert(next);
                        que.push(next);
                    }
                }
            }
            qsize = que.size();
        }
        return res;
    }
    bool isValid(string s) {
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '(' && s[i] != ')')
                continue;
            if (s[i] == '(')
                ++left;
            else if (--left < 0)
                return false;
        }
        return left == 0;
    }
};