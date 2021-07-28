//--- Q: 0477. Total Hamming Distance

//--- method 1: 32bit operation, O(n)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (auto &num: nums) {
                ones += (num&1);
                num >>= 1;
            }
            res += ones*(nums.size()-ones);
        }
        return res;
    }
};