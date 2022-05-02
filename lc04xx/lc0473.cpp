//--- Q: 0473. Matchsticks to Square

//--- method 1: dp recursion
class Solution {
public:
    vector<int> dp;
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end());
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int n = matchsticks.size();
        if (sum%4 != 0) {
            return false;
        }
        int side = sum/4;
        dp.resize(1<<n, -1);
        return dfs(0, 0, 0, side, 0, matchsticks);
    }
    int dfs(int idx, int state, int clen, int side, int cnt, vector<int> &matchsticks) {
        if (dp[state] != -1) {
            return dp[state];
        }
        if (cnt == 4) {
            return dp[state] = 1;
        }
        for (int i = idx; i < matchsticks.size(); ++i) {
            if (!(state&(1<<i))) {
                int rtn = 0;
                if (clen+matchsticks[i] == side) {
                    rtn = dfs(0, state|(1<<i), 0, side, cnt+1, matchsticks);
                } else if (clen+matchsticks[i] < side) {
                    rtn = dfs(i+1, state|(1<<i), clen+matchsticks[i], side, cnt, matchsticks);
                }
                if (rtn) {
                    return dp[state] = 1;
                }
            }
        }
        return dp[state] = 0;
    }
};

//--- method 2: dp iteration
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int n = matchsticks.size();
        if (sum%4 != 0) {
            return false;
        }
        int side = sum/4;
        vector<int> dp(1<<n, -1);
        dp[0] = 0;
        for (int state = 0; state < (1<<n); ++state) {
            if (dp[state] == -1) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (!(state&(1<<j)) && dp[state]+matchsticks[j] <= side) {
                    dp[state|(1<<j)] = (dp[state]+matchsticks[j])%side;
                }
            }
        }
        return dp.back() == 0;
    }
};