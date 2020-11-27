//--- Q: 1087. Brace Expansion

//--- method 1: normal dfs, permutation
class Solution {
public:
    vector<string> expand(string S) {
        vector<string> res;
        string now = "";
        dfs(0, now, S, res);
        return res;
    }
    void dfs(int idx, string &now, string &s, vector<string> &res) {
        if (idx == s.size()) {
            res.push_back(now);
            return;            
        }
        set<char> tmp;
        if (s[idx] == '{') {
            idx++;
            while (s[idx] != '}') {
                if (s[idx] != ',')
                    tmp.insert(s[idx]);
                ++idx;
            }
            ++idx;
            for (auto &ss: tmp) {
                now.push_back(ss);
                dfs(idx, now, s, res);
                now.pop_back();
            }
        } else {
            now.push_back(s[idx]);
            dfs(idx+1, now, s, res);
            now.pop_back();
        } 
    }
};
