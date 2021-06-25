//--- Q: 852. Peak Index in a Mountain Array

//--- method 1: binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] < nums[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};