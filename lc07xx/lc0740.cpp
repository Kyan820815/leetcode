//--- Q: 0740. Delete and Earn

//--- method 1: dp, O(n)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        for (auto &num: nums) {
            ++cnt[num];
        }
        int odd = 0, even = 0;
        for (int i = 1; i <= 10000; ++i) {
            if (i&1) {
                odd = max(even, odd+cnt[i]*i);
            } else {
                even = max(even+cnt[i]*i, odd);
            }
        }
        return max(odd, even);
    }
};
