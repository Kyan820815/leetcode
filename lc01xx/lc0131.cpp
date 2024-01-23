//--- Q: 0131. Palindrome Partitioning
//--- last written: 2023/07/14

//--- method 1: dfs with check palidrome every time
class Solution {
public:
    vector<string> res;
    vector<vector<string>> res_vec;
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res_vec;
    }
    void dfs(int idx, string &s) {
        if (idx == s.size()) {
            res_vec.push_back(res);
        }
        string tmp = "";
        for (int i = idx; i < s.size(); ++i) {
            tmp += s[i];
            if (ispal(tmp)) {
                res.push_back(tmp);
                dfs(i+1, s);
                res.pop_back();
            }
        }
    }
    bool ispal(string &str) {
        int left = 0, right = str.size()-1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: dfs with pre-computed palidrome, better
class Solution {
public:
    vector<string> res;
    vector<vector<string>> res_vec;
    vector<vector<int>> dp;
    vector<vector<string>> partition(string s) {
        dp.resize(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size()-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < s.size(); ++j) {
                if ((i+1 == j || dp[i+1][j-1]) && s[i] == s[j]) {
                    dp[i][j] = 1;
                }
            }
        }
        dfs(0, s);
        return res_vec;
    }
    void dfs(int idx, string &s) {
        if (idx == s.size()) {
            res_vec.push_back(res);
        }
        string tmp = "";
        for (int i = idx; i < s.size(); ++i) {
            tmp += s[i];
            if (dp[idx][i]) {
                res.push_back(tmp);
                dfs(i+1, s);
                res.pop_back();
            }
        }
    }
};

