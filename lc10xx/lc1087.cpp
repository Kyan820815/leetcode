//--- Q: 1087. Brace Expansion

//--- method 1: iteration
class Solution {
public:
    vector<string> expand(string s) {
        vector<string> res = {""};
        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] == '{') {
                ++idx;
                vector<string> tmp;
                while (s[idx] != '}') {
                    if (isalpha(s[idx])) {
                        for (auto &str: res) {
                            tmp.push_back(str+s[idx]);
                        }
                    }
                    ++idx;
                }
                res = tmp;
            } else {
                for (auto &str: res) {
                    str += s[idx];
                }
            }
            ++idx;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//--- method 2: dfs recursion
class Solution {
public:
    vector<string> res;
    vector<string> expand(string s) {
        string str = "";
        dfs(0, s, str);
        sort(res.begin(), res.end());
        return res;
    }
    void dfs(int idx, string &s, string &str) {
        if (idx == s.size()) {
            res.push_back(str);
            return;
        }
        vector<char> pool;
        if (s[idx] == '{') {
            while (s[idx] != '}') {
                if (isalpha(s[idx])) {
                    pool.push_back(s[idx]);
                }
                ++idx;
            }
        } else {
            pool.push_back(s[idx]);
        }
        for (auto &ch: pool) {
            str += ch;
            dfs(idx+1, s, str);
            str.pop_back();
        }
    }
};