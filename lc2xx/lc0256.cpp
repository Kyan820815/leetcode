//--- Q: 256. Paint House

//--- method 1: O(1) space dp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (!costs.size()) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            costs[i][0] = min(costs[i-1][1], costs[i-1][2]) + costs[i][0];
            costs[i][1] = min(costs[i-1][2], costs[i-1][0]) + costs[i][1];
            costs[i][2] = min(costs[i-1][0], costs[i-1][1]) + costs[i][2];
        }
        return min(costs[n-1][0], min(costs[n-1][1], costs[n-1][2]));
    }
};