//--- Q: 0300. Longest Increasing Subsequence

//--- method 1: binary search to find appropiate location of res
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = res.size()-1;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (res[mid] < nums[i]) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
            if (!res.size() || res[left] < nums[i]) {
                res.push_back(nums[i]);
            } else {
                res[left] = nums[i];
            }
        }
        return res.size();
    }
};