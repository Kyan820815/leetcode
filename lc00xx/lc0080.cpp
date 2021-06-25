//--- Q: 80. Remove Duplicates from Sorted Array II

//--- method 1: two pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2, idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (idx < k || nums[i] > nums[idx-k]) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};

//--- method 2: counting
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = -1, cnt = 0, last = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != last) {
                cnt = 0;
            }
            last = nums[i];
            if (++cnt <= 2) {
                swap(nums[++idx], nums[i]);
            }
        }
        return idx+1;
    }
};