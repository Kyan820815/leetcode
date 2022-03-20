//--- Q: 1055. Shortest Way to Form String

//--- method 1: O(n + m^2)
class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.size(), m = target.size();
        vector<vector<int>> cnt(n, vector<int>(26, -1));
        for (int i = 0; i < n; ++i) {
            cnt[i][source[i]-'a'] = i;
            if (i+1 < n) {
                cnt[i+1] = cnt[i];
            }
        }
        vector<int> dp(m+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= m; ++i) {
            int start = n-1;
            for (int j = i; j >= 1 && start >= 0; --j) {
                start = cnt[start][target[j-1]-'a'];
                if (start == -1) {
                    if (j == i) {
                        return -1;
                    } else {
                        break;
                    }
                }
                --start;
                dp[i] = min(dp[i], 1+dp[j-1]);
            }
        }
        return dp[m];
    }
};

//--- method 2: O(n + m)
class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.size(), m = target.size();
        vector<vector<int>> cnt(n, vector<int>(26, -1));
        for (int i = 0; i < n; ++i) {
            cnt[i][source[i]-'a'] = i;
            if (i+1 < n) {
                cnt[i+1] = cnt[i];
            }
        }
        int res = 0, start = n-1;
        for (int i = m-1; i >= 0; --i) {
            if (cnt[n-1][target[i]-'a'] == -1) {
                return -1;
            }
            int next = cnt[start][target[i]-'a'];
            if (next == -1) {
                ++res;
                start = cnt[n-1][target[i]-'a']-1;
            } else {
                start = next-1;
                if (start == -1) {
                    ++res;
                    start = n-1;
                }
            }
        }
        return (start >= 0 && start != n-1) ? res+1 : res;
    }
};
