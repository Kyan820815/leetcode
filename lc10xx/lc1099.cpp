//--- Q: 1099. Two Sum Less Than K

//--- method 1: two pointers
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1, res = 0;
        while (left < right) {
            if (nums[left] + nums[right] < k) {
                res = max(res, nums[left]+nums[right]);
                ++left;
            } else {
                --right;
            }
        }
        return !res ? -1 : res;
    }
};