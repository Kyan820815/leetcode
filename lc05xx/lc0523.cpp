//--- Q: 0523. Continuous Subarray Sum

//--- method 1: dp iteration with memorizing first remainder index
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % k;
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            } else if (i-map[sum] > 1) {
                return true;
            }
        }
        return false;
    }
};