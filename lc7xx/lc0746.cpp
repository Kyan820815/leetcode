//--- Q: 746. Min Cost Climbing Stairs

//--- method 1: O(1) space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i_1 = 0, i_2 = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int now = min(i_1+cost[i-1], i_2+cost[i-2]);
            i_2 = i_1;
            i_1 = now;
        }
        return i_1;
    }
};