//--- Q: 283. Move Zeroes

//--- method 1: swap
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] != 0)
        		swap(nums[i], nums[++zero]);
        }
    }
};

//--- method 2: add zero after iteration
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] != 0)
        		nums[++zero] = nums[i];
        }
        for (int i = zero+1; i < nums.size(); ++i)
        	nums[i] = 0;
    }
};