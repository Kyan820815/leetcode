//--- Q: 1913. Maximum Product Difference Between Two Pairs

//--- method 1: linear processing
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size(), fidmin, sidmin, fidmax, sidmax;
        fidmin = sidmin = fidmax = sidmax = -1;
        for (int i = 0; i < n; ++i) {
            if (fidmax == -1 || nums[i] >= nums[fidmax]) {
                sidmax = fidmax;
                fidmax = i;
            } else if (sidmax == -1 || nums[i] >= nums[sidmax]) {
                sidmax = i;
            }
            if (fidmin == -1 || nums[i] <= nums[fidmin]) {
                sidmin = fidmin;
                fidmin = i;
            } else if (sidmin == -1 || nums[i] <= nums[sidmin]) {
                sidmin = i;
            }
        }
        return nums[fidmax]*nums[sidmax] - nums[fidmin]*nums[sidmin];
    }
};

//--- method 2: sort
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        return nums[n-1]*nums[n-2] - nums[0]*nums[1];
    }
};