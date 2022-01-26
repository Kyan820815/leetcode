//--- Q: 1140. Stone Game II

//--- method 1: dp
class Solution {
public:
    vector<vector<int>> dp;
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int>(n+1, -1));
        for (int i = n-1; i > 0; --i) {
            piles[i-1] += piles[i];
        }
        return dfs(0, 1, piles);
    }
    int dfs(int idx, int m, vector<int> &piles) {
        if (idx == piles.size()) {
            return 0;
        }
        if (dp[idx][m] != -1) {
            return dp[idx][m];
        }
        int minv = INT_MAX;
        for (int i = 1; i <= 2*m; ++i) {
            if (i+idx > piles.size()) {
                break;
            }
            minv = min(minv, dfs(idx+i, max(i,m), piles));
        }
        return dp[idx][m] = piles[idx]-minv;
    }
};