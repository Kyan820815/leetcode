//--- Q: 1031. Maximum Sum of Two Non-Overlapping Subarrays

//--- method 1: sliding window
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i-1];
        }
        int firstMax = nums[firstLen-1], secondMax = nums[secondLen-1], res = nums[firstLen+secondLen-1];
        for (int i = firstLen+secondLen; i < n; ++i) {
            firstMax = max(firstMax, nums[i-secondLen]-nums[i-firstLen-secondLen]);
            secondMax = max(secondMax, nums[i-firstLen]-nums[i-firstLen-secondLen]);
            res = max(res, max(firstMax+nums[i]-nums[i-secondLen], secondMax+nums[i]-nums[i-firstLen]));
        }
        return res;
    }
};