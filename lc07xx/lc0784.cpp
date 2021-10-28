//--- Q: 0784. Letter Case Permutation

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string> que;
        que.push("");
        for (int i = 0; i < s.size(); ++i) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                que.push(now+s[i]);
                if (!isdigit(s[i])) {
                    string ch(1, s[i]^32);
                    que.push(now+ch);
                }
            }
        }
        vector<string> res;
        while (que.size()) {
            res.push_back(que.front());
            que.pop();
        }
        return res;
    }
};

//--- method 2: queue
class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        string sol = "";
        dfs(0, s, sol);
        return res;
    }
    void dfs(int idx, string &s, string &sol) {
        if (idx == s.size()) {
            res.push_back(sol);
            return;
        }
        sol += s[idx];
        dfs(idx+1, s, sol);
        sol.pop_back();
        if (!isdigit(s[idx])) {
            sol += (s[idx]^32);
            dfs(idx+1, s, sol);
            sol.pop_back();
        }
    }
};

//--- methid 3: iteration
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res = {""};
        for (auto &ch: s) {
            if (isdigit(ch)) {
                for (auto &str: res) {
                    str += ch;
                }
            } else {
                int sz = res.size();
                for (int i = 0; i < sz; ++i) {
                    auto tmp = res[i];
                    res[i] += ch;
                    tmp += ch^32;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};