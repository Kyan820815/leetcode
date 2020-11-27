//--- Q: 1025. Divisor Game

//--- method 1: dfs recursion
class Solution {
public:
    bool divisorGame(int N) {
        if (N == 1) return false;
        vector<int> dp(N+1, -1);
        dp[1] = 0;
        return dfs(N, dp);
    }
    bool dfs(int N, vector<int> &dp)
    {
        if (dp[N] != -1) return dp[N];
        int res = 1;
        for (int i = 1; i < N; ++i)
        {
            if (N%i == 0)
                res &= dfs(N-i, dp);
            if (res == 0) break;
        }
        return dp[N] = !res;
    }
};

//--- method 2: find regular pattern
class Solution {
public:
    bool divisorGame(int N) {
        return N%2 == 0;
    }
};