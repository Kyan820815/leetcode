//--- Q: 1150. Check If a Number Is Majority Element in a Sorted Array

//--- method 1: binary search, better
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int first = find(target, nums);
        return nums[first] == target && first + nums.size()/2 < nums.size() && nums[first + nums.size()/2] == target;
    }
    int find(int target, vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

//--- method 2: binary search
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int first = findf(target, nums);
        int last = findl(target, nums);
        return nums[first] == target && nums[last] == target && (last-first+1) > nums.size()/2;
    }
    int findf(int target, vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int findl(int target, vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if (nums[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};
