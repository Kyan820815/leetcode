//--- Q: 0140. Word Break II

//--- method 1: dp recursion
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return dfs(0, s, set);
    }
    vector<string> dfs(int idx, string s, unordered_set<string> &set) {
        if (idx == s.size()) {
            return {""};
        }
        vector<string> res;
        string tmp = "";
        for (int i = idx; i < s.size(); ++i) {
            tmp += s[i];
            if (set.find(tmp) == set.end()) {
                continue;
            }
            auto rtn_vec = dfs(i+1, s, set);
            for (auto &str: rtn_vec) {
                res.push_back(tmp + (str == "" ? "" : " ") + str);
            }
        }
        return res;
    }
};