//--- Q: 0097. Interleaving String
//--- last written: 2023/04/08

//--- method 1: dp recursion
class Solution {
public:
    vector<int> visit;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) {
            return false;
        }
        visit.resize((s1.size()+1)*100+s2.size()+1, -1);
        return dfs(0, 0, 0, s1, s2, s3);
    }
    int dfs(int i, int j, int k, string &s1, string &s2, string &s3) {
        int n = s1.size(), m = s2.size(), l = s3.size();
        int tag = i*100+j;
        if (visit[tag] != -1) {
            return visit[tag];
        }
        while (i < n || j < m) {
            if (i < n && j < m && s2[j] == s3[k] && s1[i] == s3[k]) {
                return visit[tag] = dfs(i+1, j, k+1, s1, s2, s3) || dfs(i, j+1, k+1, s1, s2, s3);
            } else if (i < n && s1[i] == s3[k]) {
                ++i, ++k;
            } else if (j < m && s2[j] == s3[k]) {
                ++j, ++k;
            } else {
                return visit[tag] = 0;
            }
        }
        return visit[tag] = 1;
    }
};

//--- method 2: dp iteration
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) {
            return false;
        }
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1] || dp[i-1][j] && s1[i-1] == s3[i+j-1];
            }
        }
        return dp[n][m];
    }
};

//--- method 3: dp iteration O(n) space
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) {
            return false;
        }
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        for (int j = 1; j <= m; ++j) {
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];
        }
        for (int i = 1; i <= n; ++i) {
            dp[0] = dp[0] && s1[i-1] == s3[i-1];
            for (int j = 1; j <= m; ++j) {
                dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1] || dp[j] && s1[i-1] == s3[i+j-1];
            }
        }
        return dp[m];
    }
};
