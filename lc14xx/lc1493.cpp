//--- Q: 1493. Longest Subarray of 1's After Deleting One Element

//--- method 1: two pointer sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        for (int left = 0, right = 0, k = 1; right < nums.size(); ++right) {
            k -= !nums[right];
            for (; k < 0;) {
                k += !nums[left++];
            }
            res = max(res, right-left);
        }
        return res;
    }
};