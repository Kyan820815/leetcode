//--- Q: 1140. Stone Game II

//--- method 1: dp recursion
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1, vector<int>(piles.size()+1, -1));
        vector<int> psum(piles.size()+1, 0);
        int m = 1;
        for (int i = piles.size()-1; i >= 0; i--)
            psum[i] = psum[i+1] + piles[i];
        return dfs(0, piles, 1, dp, psum);
    }
    int dfs(int idx, vector<int> &piles, int m, vector<vector<int>> &dp, vector<int> &psum) {
        int minv = INT_MAX;
        if (dp[idx][m] != -1)
            return dp[idx][m];
        if (idx + 2*m >= piles.size())
            return dp[idx][m] = psum[idx];
        for (int i = 1; i <= 2*m && idx+i < piles.size(); ++i)
            minv = min(minv, dfs(idx+i, piles, max(m, i), dp, psum));
        return dp[idx][m] = psum[idx] - minv;
    }
    
};

//--- method 2: my version, better
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));
        vector<int> psum(piles.size(), 0);
        psum.back() = piles.back();
        for (int i = piles.size()-2; i >= 0; --i) {
            psum[i] = psum[i+1] + piles[i];
        }
        return dfs(0, 1, psum, dp);
    }
    int dfs(int now, int M, vector<int> &psum, vector<vector<int>> &dp) {
        int minv = INT_MAX;
        if (now >= psum.size()) {
            return 0;
        }
        if (dp[now][M] != -1) {
            return dp[now][M];
        }
        for (int i = 1; i <= 2*M; ++i) {
            int val = (now+i >= psum.size()) ? 0 : dfs(now+i, max(i, M), psum, dp);
            minv = min(minv, val);
        }
        return dp[now][M] = psum[now] - minv;
    }
};