//--- Q: 0041. First Missing Positive
//--- last written: 2023/03/14

//--- method 1: swap method O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i+1 != nums[i]) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
