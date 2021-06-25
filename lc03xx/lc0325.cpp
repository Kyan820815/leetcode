//--- Q: 325. Maximum Size Subarray Sum Equals k

//--- method 1: prefix sum
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int sum = 0, res = 0;
        map[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
            if (map.find(sum-k) != map.end()) {
                res = max(res, i-map[sum-k]);
            }
        }
        return res;
    }
};