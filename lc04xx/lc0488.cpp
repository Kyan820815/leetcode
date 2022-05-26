//--- Q: 0488. Zuma Game

//--- method 1: dfs with memorization
class Solution {
public:
    unordered_map<string,int> m;
    int findMinStep(string board, string hand) {
        unordered_map<char,int> cnt;
        for (auto &ch: hand) {
            ++cnt[ch];
        }
        return dfs(board, cnt);
    }
    int dfs(string &s, unordered_map<char,int> &cnt) {
        s = remove(s);
        if (!s.size()) {
            return 0;
        }
        string tag = s;
        for (auto &[ch, val]: cnt) {
            tag += ch + to_string(val);
        }
        if (m.find(tag) != m.end()) {
            return m[tag];
        }
        int minv = INT_MAX;
        for (auto &[ch, val]: cnt) {
            if (!val) {
                continue;
            }
            for (int i = 0; i <= s.size(); ++i) {
                if (i && s[i-1] == ch) {
                    continue;
                }
                if (s[i] == ch || i && s[i] == s[i-1]) {
                    string next = s.substr(0,i)+ch+s.substr(i);
                    --val;
                    int rtn = dfs(next, cnt);
                    if (rtn >= 0) {
                        minv = min(minv, rtn);
                    }
                    ++val;
                }
            }
        }
        return m[tag] = minv == INT_MAX ? -1 : minv+1;
    }
    string remove(string &s) {
        int i = 0, j = 0;
        while (i <= s.size()) {
            if (i == s.size() || s[i] != s[j]) {
                if (i-j >= 3) {
                    string next = s.substr(0,j) + s.substr(i);
                    return remove(next);
                }
                j = i;
            }
            ++i;
        }
        return s;
    }
};