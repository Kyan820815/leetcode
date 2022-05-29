//--- Q: 1856. Maximum Subarray Min-Product

//--- method 1: stack and prefix sum
class Solution {
public:
    using ll = long long;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size(), mod = 1e9+7;
        vector<ll> psum = {nums[0]};
        for (int i = 1; i < n; ++i) {
            psum.push_back(psum.back()+nums[i]);
        }
        ll res = 0;
        vector<int> sk;
        nums.push_back(0);
        ++n;
        for (int i = 0; i < n; ++i) {
            while (sk.size() && nums[sk.back()] > nums[i]) {
                int idx = sk.back();
                sk.pop_back();
                ll lsum = sk.size() ? psum[sk.back()] : 0;
                res = max(res, (psum[i-1]-lsum)*nums[idx]);
            }
            sk.push_back(i);
        }
        return res%mod;
    }
};