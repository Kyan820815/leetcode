//--- Q: 0016. 3Sum Closest
//--- last written: 2023/06/01

//--- method 1: sort and O(n^2) find
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff, absdiff = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n-2; ++i) {
            if (i && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1, right = n-1, t = target-nums[i];
            while (left < right) {
                auto cur_diff = t-(nums[left]+nums[right]);
                if (abs(cur_diff) < absdiff) {
                    absdiff = abs(cur_diff);
                    diff = cur_diff;
                }
                if (cur_diff > 0) {
                    ++left;
                } else if (cur_diff < 0) {
                    --right;
                } else {
                    return target;
                }
            }
        }
        return target-diff;
    }
};
