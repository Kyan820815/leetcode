//--- Q: 0560. Subarray Sum Equals K

//--- method 1: dp with map, prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0, res = 0;
        for (auto &num: nums) {
            sum += num;
            res += map[sum-k];
            ++map[sum];
        }
        return res;
    }
};