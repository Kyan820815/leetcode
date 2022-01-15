//--- Q: 1029. Two City Scheduling

//--- method 1: sort diff of costs for each person
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0]-a[1] < b[0]-b[1];
        });
        int n = costs.size(), res = 0;
        for (int i = 0; i < n/2; ++i) {
            res += costs[i][0];
        }
        for (int i = n/2; i < n; ++i) {
            res += costs[i][1];
        }
        return res;
    }
};