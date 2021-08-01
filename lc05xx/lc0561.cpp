//--- Q: 0561. Array Partition I

//--- method 1: greedy search
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> cnt(20001, 0);
        for (auto &num: nums) {
            ++cnt[num+10000];
        }
        int choose = 1, res = 0;
        for (int i = 0; i < cnt.size(); ++i) {
            while (cnt[i]--) {
                res += (choose ? (i-10000) : 0);
                choose ^= 1;
            }
        }
        return res;
    }
};