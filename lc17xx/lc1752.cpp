//--- Q: 1752. Check if Array Is Sorted and Rotated

//--- method 1: check two parts
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), first = nums[0], i;
        for (i = 1; i < n; ++i) {
            if (nums[i-1] > nums[i]) {
                break;
            }
        }
        for (; i < n; ++i) {
            if (first < nums[i] || i+1 < n && nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};

//--- method 2: only one chance for nums[i] > nums[i+1]
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i+1)%n] && ++k > 1) {
                return false;
            }
        }
        return true;
    }
};
