//--- Q: 1947. Maximum Compatibility Score Sum

//--- method 1: dp iteration
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size(), m = students[0].size(), res = 0;
        vector<vector<int>> arr(n, vector<int>(n));
        vector<vector<int>> dp(n+1, vector<int>(1<<n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int score = 0;
                for (int k = 0; k < m; ++k) {
                    score += students[i][k] == mentors[j][k];
                }
                arr[i][j] = score;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < (1<<n); ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[j-1][i] == -1) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (!(i & (1<<k))) {
                        dp[j][i|(1<<k)] = max(dp[j][i|(1<<k)], dp[j-1][i] + arr[j-1][k]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            res = max(res, dp[i][(1<<n)-1]);
        }
        return res;
    }
};

//--- method 2: dp recursion
class Solution {
public:
    vector<vector<int>> arr, dp;
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size(), m = students[0].size();
        arr.resize(n, vector<int>(n));
        dp.resize(n, vector<int>(1<<n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int score = 0;
                for (int k = 0; k < m; ++k) {
                    score += students[i][k] == mentors[j][k];
                }
                arr[i][j] = score;
            }
        }
        return dfs(0, 0, students, mentors);
    }
    int dfs(int idx, int mask, vector<vector<int>> &students, vector<vector<int>> &mentors) {
        if (idx == students.size()) {
            return 0;
        }
        if (dp[idx][mask] != -1) {
            return dp[idx][mask];
        }
        int score = 0;
        for (int i = idx; i < students.size(); ++i) {
            for (int j = 0; j < mentors.size(); ++j) {
                if (!(mask & (1<<j))) {
                    score = max(score, dfs(i+1, mask|(1<<j), students, mentors)+arr[i][j]);
                }
            }
        }
        return dp[idx][mask] = score;
    }
};

//--- method 2: next_premutation
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size(), m = students[0].size(), res = 0;
        vector<vector<int>> arr(n, vector<int>(n));
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            pos.push_back(i);
            for (int j = 0; j < n; ++j) {
                int score = 0;
                for (int k = 0; k < m; ++k) {
                    score += students[i][k] == mentors[j][k];
                }
                arr[i][j] = score;
            }
        }
        do {
            int score = 0;
            for (int i = 0; i < n; ++i) {
                score += arr[i][pos[i]];
            }
            res = max(res, score);
        } while (next_permutation(pos.begin(), pos.end()));
        return res;
    }
};