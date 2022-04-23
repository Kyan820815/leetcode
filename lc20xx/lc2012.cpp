//--- Q: 2012. Sum of Beauty in the Array

//--- method 1: two pass
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> minval(n, INT_MAX);
        int right = INT_MAX;
        for (int j = n-1; j >= 0; --j) {
            right = min(right, nums[j]);
            minval[j] = right;
        }
        int res = 0, maxv = nums[0];
        for (int i = 1; i < n-1; ++i) {
            if (maxv < nums[i] && nums[i] < minval[i+1]) {
                res += 2;
            } else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ++res;
            }
            maxv = max(maxv, nums[i]);
        }
        return res;
    }
};