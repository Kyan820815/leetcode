//--- Q: 0031. Next Permutation

//--- method 1: find the pattern
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size();
        for (int i = nums.size()-1; i >=1; --i) {
            if (nums[i-1] < nums[i]) {
                idx = i-1;
                break;
            }
        }
        if (idx == nums.size()) {
            reverse(nums.begin(), nums.end());
        } else {
            int last;
            for (int i = idx+1; i < nums.size(); ++i) {
                if (nums[i] > nums[idx]) {
                    last = i;
                }
            }
            swap(nums[last], nums[idx]);
            reverse(nums.begin()+idx+1, nums.end());
        }
    }
};