//--- Q: 456. 132 Pattern

//--- method 1: stack
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> sk;
        int third = INT_MIN;
        for (int i = nums.size()-1; i >= 0; --i) {
            if (third > nums[i])
                return true;
            while (sk.size() && sk.back() < nums[i]) {
                third = sk.back();
                sk.pop_back();
            }
            sk.push_back(nums[i]);
        }
        return false;
    }
};

//--- follow up: find all 132 pattern
class Solution {
public:
    vector<vector<int>> find132pattern(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j])
                        res.push_back({nums[i], nums[j], nums[k]})                        
                }
            }
        }
        return res;
    }
};

