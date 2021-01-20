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