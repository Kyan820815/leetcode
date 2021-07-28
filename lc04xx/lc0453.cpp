//--- Q: 0453. Minimum Moves to Equal Array Elements

//--- method 1: make all to minimum value
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minv = INT_MAX, sum = 0;
        for (auto &num: nums) {
            sum += num;
            minv = min(minv, num);
        }
        return sum-minv*nums.size();
    }
};