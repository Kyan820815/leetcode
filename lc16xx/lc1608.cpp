//--- Q: 1608. Special Array With X Elements Greater Than or Equal X

//--- method 1: sort then linaer search
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i >= 0; --i) {
            int x = nums.size()-i;
            if (nums[i] >= x && (!i || x > nums[i-1])) {
                return nums.size()-i;
            }
        }
        return -1;
    }
};

//--- method 2: sort then binary search
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] >= n-mid) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        if (nums[left] >= n-left && (!left || n-left > nums[left-1])) {
            return n-left;
        } else {
            return -1;
        }
    }
};