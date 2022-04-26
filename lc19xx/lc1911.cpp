//--- Q: 1911. Maximum Alternating Subsequence Sum

//--- method 1: odd and even subsequence
class Solution {
public:
    using ll = long long;
    long long maxAlternatingSum(vector<int>& nums) {
        ll even = 0, odd = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ll lodd = odd, leven = even;
            odd = max(lodd, leven+nums[i]);
            even = max(leven, lodd-nums[i]);
        }
        return odd;
    }
};