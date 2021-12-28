//--- Q: 0915. Partition Array into Disjoint Intervals

//--- method 1: O(n) space
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> minarr(nums.size(), INT_MAX);
        int minv = INT_MAX;
        for (int i = nums.size()-1; i >= 0; --i) {
            minv = min(minv, nums[i]);
            minarr[i] = minv;
        }
        int maxv = INT_MIN;
        for (int i = 0; i < nums.size()-1; ++i) {
            maxv = max(maxv, nums[i]);
            if (maxv <= minarr[i+1]) {
                return i+1;
            }
        }
        return -1;
    }
};

//--- method 1: O(1) space
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxv = nums[0], lmaxv = nums[0], idx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            maxv = max(maxv, nums[i]);
            if (lmaxv > nums[i]) {
                lmaxv = maxv;
                idx = i;
            }
        }
        return idx+1;
    }
};