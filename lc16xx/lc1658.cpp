//--- Q: 1658. Minimum Operations to Reduce X to Zero

//--- method 1: two pointers
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum-x;
        int res = -1, left = 0, right = 0;
        sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (left <= right && sum > target) {
                sum -= nums[left++];
            }
            if (sum == target) {
                res = max(res, right-left+1);
            }
            ++right;
        }
        return res == -1 ? -1 : nums.size()-res;
    }
};

