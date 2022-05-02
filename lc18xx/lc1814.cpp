//--- Q: 1814. Count Nice Pairs in an Array

//--- method 1: counting
class Solution {
public:
    using ll = long long;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int mod = 1e9+7, res = 0;
        auto rv = [](int num) {
            int rvnum = 0;
            while (num) {
                rvnum = rvnum*10 + num%10;
                num /= 10;
            }
            return rvnum;
        };
        for (auto &num: nums) {
            res = (res+map[num-rv(num)]++) % mod;
        }
        return res;
    }
};