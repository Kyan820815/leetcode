//--- Q: 1748. Sum of Unique Elements

//--- method 1: count
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int res = 0;
        for (auto &num: nums) {
            if (++cnt[num] == 1) {
                res += num;
            } else if (cnt[num] == 2) {
                res -= num;
            }
        }
        return res;
    }
};