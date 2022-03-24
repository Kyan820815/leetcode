//--- Q: 2006. Count Number of Pairs With Absolute Difference K

//--- method 1: prefix sum
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int res = 0;
        for (auto &num: nums) {
            res += map[num-k] + map[num+k];
            ++map[num];
        }
        return res;
    }
};

//--- method 2: counting
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> cnt(101, 0);
        int res = 0;
        for (auto &num: nums) {
            ++cnt[num];
        }
        for (int i = k+1; i <= 100; ++i) {
            res += cnt[i] * cnt[i-k];
        }
        return res;
    }
};