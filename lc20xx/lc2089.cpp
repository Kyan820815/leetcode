//--- Q: 2089. Find Target Indices After Sorting Array

//--- method 1: sort
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size() && nums[i] <= target; ++i) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> cnt(101, 0), res;
        for (auto &num: nums) {
            ++cnt[num];
        }
        int start = 0;
        for (int i = 1; i <= 100; ++i) {
            if (i < target) {
                start += cnt[i];
            } else if (i == target) {
                for (int j = 0; j < cnt[i]; ++j) {
                    res.push_back(start+j);
                }
                return res;
            }
        }
        return res;
    }
};