//--- Q: 0922. Sort Array By Parity II

//--- method 1: O(1) space, swap
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j = 1; i < n && j < n; i += 2, j += 2) {
            while (i < n && !(nums[i]&1)) {
                i += 2;
            }
            while (j < n && nums[j]&1) {
                j += 2;
            }
            if (i < n && j < n) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};