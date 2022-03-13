//--- Q: 2150. Find All Lonely Numbers in the Array

//--- method 1: bucket sort
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> cnt(1000002, 0);
        for (auto &num: nums) {
            ++cnt[num];
        }
        vector<int> res;
        for (int i = 0; i <= 1000000; ++i) {
            if (cnt[i] == 1 && (!i || !cnt[i-1]) && !cnt[i+1]) {
                res.push_back(i);
            }
        }
        return res;
    }
};

//--- method 2: nlogn sort
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if ((!i || nums[i-1]+1 < nums[i]) && (i == nums.size()-1 || nums[i] < nums[i+1]-1)) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};