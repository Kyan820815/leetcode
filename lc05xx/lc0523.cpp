//--- Q: 523. Continuous Subarray Sum

//--- method 1: dp iteration with memorizing first remainder index
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int right = 0, sum = 0;
        unordered_map<int, int> map;
        map[0] = -1;
        while (right < nums.size()) {
            sum += nums[right];
            int val = k ? sum%k : val;
            if (map.find(val) != map.end()) {
                if (right-map[val] > 1) {
                    return true;
                }
            } else {
                map[val] = right;
            }
            ++right;
        }
        return false;
    }
};