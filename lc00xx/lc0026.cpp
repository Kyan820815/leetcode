//--- Q: 0026. Remove Duplicates from Sorted Array
//--- last written: 2023/07/02

//--- method 1: partion tech of quick select
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (idx == -1 || nums[idx] != nums[i]) {
                swap(nums[++idx], nums[i]);
            }
        }
        return idx+1;
    }
};
