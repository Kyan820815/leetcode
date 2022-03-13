//--- Q: 2188. Minimum Time to Finish the Race

//--- method 1: top down dp recursion
class Solution {
public:
    vector<int> best, dp;
    int maxl;
    using ll = long long;
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        best.resize(1001, INT_MAX), dp.resize(numLaps+1, INT_MAX);
        for (auto &tire: tires) {
            int i, totalTime = 0;
            ll time;
            for (i = 1, time = tire[0]; i <= numLaps && time <= changeTime+tire[0]; ++i, time*=tire[1]) {
                totalTime += time;
                if (best[i] > totalTime) {
                    best[i] = totalTime;
                }
            }
            maxl = max(maxl, i-1);
        }
        return dfs(numLaps, changeTime);
    }
    int dfs(int nl, int ct) {
        if (!nl) {
            return -ct;
        }
        if (dp[nl] != INT_MAX) {
            return dp[nl];
        }
        for (int i = 1; i <= min(maxl, nl); ++i) {
            dp[nl] = min(dp[nl], best[i]+ct+dfs(nl-i, ct));
        }
        return dp[nl];
    }
};

//--- method 2: bottom up dp iteration
class Solution {
public:
    vector<int> best, dp;
    int maxl;
    using ll = long long;
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        best.resize(18, INT_MAX), dp.resize(numLaps+1, INT_MAX);
        dp[0] = -changeTime;
        for (auto &tire: tires) {
            int i, totalTime = 0;
            ll time;
            for (i = 1, time = tire[0]; i <= numLaps && time <= changeTime+tire[0]; ++i, time*=tire[1]) {
                totalTime += time;
                if (best[i] > totalTime) {
                    best[i] = totalTime;
                }
            }
            maxl = max(maxl, i-1);
        }
        for (int i = 1; i <= numLaps; ++i) {
            int lmax = min(i, maxl);
            for (int j = 1; j <= lmax; ++j) {
                dp[i] = min(dp[i], best[j]+changeTime+dp[i-j]);
            }
        }
        return dp[numLaps];
    }
};