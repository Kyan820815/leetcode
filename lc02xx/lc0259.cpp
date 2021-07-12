//--- Q: 0259. 3Sum Smaller

//--- method 1: two pointer
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = n-1; i > 1; --i) {
            int t = target-nums[i];
            int left = 0, right = i-1;
            while (left < right) {
                if (nums[left] + nums[right] < t) {
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