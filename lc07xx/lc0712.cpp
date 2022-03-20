//--- Q: 0712. Minimum ASCII Delete Sum for Two Strings

//--- method 1: O(mn) space
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> cost(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            cost[i][0] = cost[i-1][0] + (int)s1[i-1];
        }
        for (int j = 1; j <= m; ++j) {
            cost[0][j] = cost[0][j-1] + (int)s2[j-1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    cost[i][j] = cost[i-1][j-1];
                } else {
                    int top = cost[i-1][j]+(int)s1[i-1];
                    int bottom = cost[i][j-1]+(int)s2[j-1];
                    cost[i][j] = top > bottom ? bottom : top;
                }
            }
        }
        return cost[n][m];
    }
};

//--- method 2: O(n) space
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> cost(m+1, 0);
        for (int j = 1; j <= m; ++j) {
            cost[j] = cost[j-1] + (int)s2[j-1];
        }
        for (int i = 1; i <= n; ++i) {
            int pre = cost[0], now;
            cost[0] += (int)s1[i-1];
            for (int j = 1; j <= m; ++j) {
                now = cost[j];
                if (s1[i-1] == s2[j-1]) {
                    cost[j] = pre;
                } else {
                    int top = cost[j]+(int)s1[i-1];
                    int bottom = cost[j-1]+(int)s2[j-1];
                    cost[j] = top > bottom ? bottom : top;
                }
                pre = now;
            }
        }
        return cost[m];
    }
};