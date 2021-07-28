//--- Q: 0442. Find All Duplicates in an Array

//--- method 1: negative checking
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i])-1] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        return res;
    }
};

//--- method 2: swapping method
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i+1 != nums[i]) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};