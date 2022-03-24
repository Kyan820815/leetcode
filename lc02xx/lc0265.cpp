//--- Q: 0265. Paint House II

//--- method 1: dp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size(), res = INT_MAX;
        int firstid = -1, secondid = -1;
        for (int i = 0; i < n; ++i) {
            int lfirstid = firstid, lsecondid = secondid;
            firstid = -1, secondid = -1;
            for (int j = 0; j < k; ++j) {
                if (i) {
                    if (lfirstid == j) {
                        costs[i][j] += costs[i-1][lsecondid];
                    } else {
                        costs[i][j] += costs[i-1][lfirstid];
                    }
                }
                if (firstid == -1 || costs[i][j] <= costs[i][firstid]) {
                    secondid = firstid;
                    firstid = j;
                } else if (secondid == -1 || costs[i][j] <= costs[i][secondid]) {
                    secondid = j;
                }
            }
        }
        return costs[n-1][firstid];
    }
};