//--- Q: 0152. Maximum Product Subarray

//--- method 1: dp, O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxv = 1, minv = 1, res = INT_MIN;
        for (auto &num: nums) {
            auto lmax = maxv, lmin = minv;
            maxv = max(num, max(lmax*num, lmin*num));
            minv = min(num, min(lmax*num, lmin*num));
            res = max(res, maxv);
        }
        return res;
    }
};