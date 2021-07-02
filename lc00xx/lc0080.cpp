//--- Q: 0080. Remove Duplicates from Sorted Array II

//--- method 1: two pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, k = 2;
        for (int i = 0; i < nums.size(); ++i) {
            if (idx < k || nums[i] != nums[idx-2]) {
                swap(nums[idx++], nums[i]);
            }
        }
        return idx;
    }
};