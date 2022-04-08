//--- Q: 1498. Number of Subsequences That Satisfy the Given Sum Condition

//--- method 1: sliding window
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = n-1, res = 0, mod = 1e9+7;
        vector<int> pow(n, 0);
        pow[0] = 1;
        for (int i = 1; i < n; ++i) {
            pow[i] = (pow[i-1]*2) % mod;
        }
        while (left <= right) {
            if (nums[left]+nums[right] > target) {
                --right;
            } else {
                res = (res + pow[right-left]) % mod;
                ++left;
            }
        }
        return res;
    }
};