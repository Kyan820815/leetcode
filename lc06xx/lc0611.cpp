//--- Q: 0611. Valid Triangle Number 

//--- method 1: O(n^2logn)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = nums.size()-1; i > 1; --i) {
            for (int left = 0, right = i-1; left < right;) {
                if (nums[left]+nums[right] > nums[i]) {
                    res += right-left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return res;
    }
};
