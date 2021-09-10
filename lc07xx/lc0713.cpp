//--- Q: 0713. Subarray Product Less Than K

//--- method 1: two pointer, one pass
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int sum = 1, left, right, res = 0;
        for (left = 0, right = 0; right < nums.size(); ++right) {
            sum *= nums[right];
            while (left <= right && sum >= k) {
                sum /= nums[left++];
            }
            res += right-left+1;
        }
        return res;
    }
};