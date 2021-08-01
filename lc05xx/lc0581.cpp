//--- Q: 0581. Shortest Unsorted Continuous Subarray

//--- method 1: O(n) two pointers
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN, left = 0, right = nums.size()-1;
        for (int i = 0, j = nums.size()-1; i < nums.size(); ++i, --j) {
            maxv = max(maxv, nums[i]);
            minv = min(minv, nums[j]);
            if (maxv > nums[i]) {
                right = i;
            }
            if (minv < nums[j]) {
                left = j;
            }
        }
        return !left && minv == nums[0] ? 0 : right-left+1;
    }
};