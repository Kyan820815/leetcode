//--- Q: 0910. Smallest Range II

//--- method 1: greedy
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = nums[n-1]-nums[0], left = nums[0]+k, right = nums[n-1]-k;
        for (int i = 0; i < n-1; ++i) {
            res = min(res, max(nums[i]+k,right)-min(nums[i+1]-k, left));
        }
        return res;
    }
};
