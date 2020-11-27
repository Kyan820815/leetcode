//--- Q: 280. Wiggle Sort

//--- method 1: greedy method
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if ((i&1) && nums[i] < nums[i-1] || !(i&1) && nums[i] > nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};