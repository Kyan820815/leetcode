//--- Q: 0268. Missing Number

//--- method 1: bit manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            res ^= (i+1);
            res ^= nums[i];
        }
        return res;
    }
};

//--- method 3: binary search
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return nums[left] == left ? left+1 : left;
    }
};