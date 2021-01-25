//--- Q: 1283. Find the Smallest Divisor Given a Threshold

//--- method 1: binary search
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1;
        for (int i = 0; i < nums.size(); ++i) {
            right = max(right, nums[i]);
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            if (find(nums, mid) > threshold) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int find(vector<int> &nums, int v) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // res += nums[i]/v + (nums[i]%v > 0);
            res += (nums[i]+v-1)/v;
        }
        return res;
    }
};