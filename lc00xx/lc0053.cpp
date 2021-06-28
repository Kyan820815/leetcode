//--- Q: 0053. Maximum Subarray

//--- method 1: dp with space O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], maxv = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxv = nums[i] + max(maxv,0);
            res = max(res, maxv);
        }
        return res;
    }
};

//--- method 2: dp with space O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], maxv = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxv = nums[i] + max(maxv,0);
            res = max(res, maxv);
        }
        return res;
    }
};