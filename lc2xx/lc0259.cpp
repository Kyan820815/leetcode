//--- Q: 259. 3Sum Smaller

//--- method 1: two pointer
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n-2; ++i) {
            if (nums[i]+nums[i+1]+nums[i+2] >= target) {
                break;
            }
            int comp = target-nums[i], left = i+1, right = n-1;
            while (left < right) {
                if (nums[left] + nums[right] < comp) {
                    res += right-left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return res;
    }
};
