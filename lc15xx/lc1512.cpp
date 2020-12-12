//--- Q: 1512. Number of Good Pairs

//--- method 1: prefix sum
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res += cnt[nums[i]];
            ++cnt[nums[i]];
        }
        return res;
    }
};