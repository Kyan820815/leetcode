//--- Q: 0238. Product of Array Except Self

//--- method 1: O(n) time, O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = 1;
        vector<int> res(n, 1);
        for (int i = 0, j = n-1; i < n; ++i, --j) {
            res[i] *= left;
            res[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }
        return res;
    }
};