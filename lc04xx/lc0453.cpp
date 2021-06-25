//--- Q: 453. Minimum Moves to Equal Array Elements

//--- method 1: make all to minimum value
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long int sum = 0;
        int minv = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            minv = min(minv, nums[i]);
            sum += nums[i];
        }
        return sum - minv*nums.size();
    }
};