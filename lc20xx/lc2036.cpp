//--- Q: 2036. Maximum Alternating Subarray Sum

//--- method 1: odd & even count subarray
class Solution {
public:
    using ll = long long;
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        ll res = nums[0], even = 0, odd = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            ll leven = even, lodd = odd;
            even = max((ll)0,lodd-nums[i]);
            odd = max((ll)nums[i], leven+(ll)nums[i]);
            res = max(res, max(even, odd));
        }
        return res;
    }
};