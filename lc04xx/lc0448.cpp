//--- Q: 0448. Find All Numbers Disappeared in an Array

//--- method 1: negative checking
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[abs(nums[i])-1] > 0) {
                nums[abs(nums[i])-1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};

//--- method 2: swap
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i+1 != nums[i]) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};