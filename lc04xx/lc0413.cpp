//--- Q: 0413. Arithmetic Slices

//--- method 1: find # of subarray ending at i
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int diff = nums[1]-nums[0], last = 0, res = 0;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i]-nums[i-1] == diff) {
                res += (i-last-1);
            } else {
                last = i-1;
                diff = nums[i]-nums[i-1];
            }
        }
        return res;
    }
};

//--- method 2: dp O(n) space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) {
                dp[i] = dp[i-1]+1;
            } else {
                dp[i] = 0;
            }
            res += dp[i];
        }
        return res;
    }
};

//--- method 3: dp O(1) space
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) {
                ++cur;
            } else {
                cur = 0;
            }
            res += cur;
        }
        return res;
    }
};