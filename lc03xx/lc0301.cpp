//--- Q: 0301. Remove Invalid Parentheses

//--- method 1: bfs
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> que;
        que.push(s);
        vector<string> res;
        while (que.size()) {
            auto qsize = que.size();
            bool finish = false;
            unordered_set<string> set;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                int left = 0;
                for (auto &ch: now) {
                    if (ch == '(') {
                        ++left;
                    } else if (ch == ')' && --left < 0) {
                        break;
                    }
                }
                if (!left) {
                    finish = true;
                    res.push_back(now);
                } else {
                    for (int i = 0; i < now.size(); ++i) {
                        if (now[i] == '(' || now[i] == ')') {
                            auto next_str = now.substr(0, i) + now.substr(i+1);
                            set.insert(next_str);
                        }
                    }
                }
            }
            if (finish) {
                break;
            } else {
                for (auto &str: set) {
                    que.push(str);
                }
            }
        }
        return res;
    }
};

//--- method 2: remove right first then left, recursion
class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        dfs(0, 0, s, {'(',')'});
        return res;
    }
    void dfs(int lasti, int lastj, string &s, pair<char, char> p) {
        int left = 0;
        for (int i = lasti; i < s.size(); ++i) {
            if (s[i] == p.first) {
                ++left;
            } else if (s[i] == p.second && --left < 0) {
                for (int j = lastj; j <= i; ++j) {
                    if ((j == lastj || s[j] != s[j-1]) && s[j] == p.second) {
                        string next_str = s.substr(0, j) + s.substr(j+1);
                        dfs(i, j, next_str, p);
                    }
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if (p.first == '(') {
            dfs(0, 0, s, {')','('});
        } else {
            res.push_back(s);
        }
    }
};