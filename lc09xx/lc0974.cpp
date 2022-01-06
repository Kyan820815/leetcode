//--- Q: 0974. Subarray Sums Divisible by K

//--- method 1: one pass
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        vector<int> prefix(k, 0);
        prefix[0] = 1;
        for (auto &num: nums) {
            sum = ((sum+num)%k+k)%k;
            res += prefix[sum];
            ++prefix[sum];
        }
        return res;
    }
};