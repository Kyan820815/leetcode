//--- Q: 0746. Min Cost Climbing Stairs

//--- method 1: revise input
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 2; i < n; ++i) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};

//--- method 2: not revise input
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i_1 = 0, i_2 = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            auto now = min(i_1+cost[i-1], i_2+cost[i-2]);
            i_2 = i_1;
            i_1 = now;
        }
        return i_1;
    }
};