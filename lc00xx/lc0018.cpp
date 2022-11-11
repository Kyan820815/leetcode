//--- Q: 0018. 4Sum
//--- last written: 2022/11/02

//--- method 1: double for loop
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; ++i) {
            if (i && nums[i] == nums[i-1]) {
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }
            for (int j = i+1; j < n-2; ++j) {
                if (j > i+1 && nums[j]== nums[j-1]) {
                    continue;
                }
                int left = j+1, right = n-1, t = target-nums[i]-nums[j];
                while (left < right) {
                    if (nums[left]+nums[right] < t) {
                        ++left;
                    } else if (nums[left]+nums[right] > t) {
                        --right;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left] == nums[left-1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right+1]) {
                            --right;
                        }
                    }
                }
            }
        }
        return res;
    }
};
