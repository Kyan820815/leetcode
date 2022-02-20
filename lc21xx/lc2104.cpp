//--- Q: 2104. Sum of Subarray Ranges

//--- method 1: two stack
class Solution {
public:
    using ll = long long;
    long long subArrayRanges(vector<int>& nums) {
        vector<int> sk;
        int n = nums.size();
        ll res = 0;
        for (int i = 0; i <= n; ++i) {
            while (sk.size() && nums[sk.back()] > (i == n ? INT_MIN : nums[i])) {
                int k = sk.back();
                sk.pop_back();
                int left = sk.size() ? sk.back() : -1;
                res -= (ll)nums[k] * (k-left) * (i-k);
            }
            if (i < n) {
                sk.push_back(i);
            }
        }        
        sk.clear();
        for (int i = 0; i <= n; ++i) {
            while (sk.size() && nums[sk.back()] < (i == n ? INT_MAX : nums[i])) {
                int k = sk.back();
                sk.pop_back();
                int left = sk.size() ? sk.back() : -1;
                res += (ll)nums[k] * (k-left) * (i-k);
            }
            if (i < n) {
                sk.push_back(i);
            }
        }

        return res;
    }
};