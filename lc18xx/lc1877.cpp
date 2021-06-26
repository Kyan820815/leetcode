//--- Q: 1877. Minimize Maximum Pair Sum in Array

//--- method 1: sort then two pointer
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1, res = 0;
        while (left < right) {
            res = max(res, nums[left++]+nums[right--]);
        }
        return res;
    }
};