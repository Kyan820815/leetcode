//--- Q: 0775. Global and Local Inversions

//--- method 1: no nums[i] > nums[j], i+2 <= j
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), maxv = nums[0];
        for (int i = 0; i < n-2; ++i) {
            maxv = max(maxv, nums[i]);
            if (maxv > nums[i+2]) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: find pattern
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (abs(i-nums[i]) > 1) {
                return false;
            }
        }
        return true;
    }
};