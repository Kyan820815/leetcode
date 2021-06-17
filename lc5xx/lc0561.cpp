//--- Q: 561. Array Partition I

//--- method 1: greedy search
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
    	int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
        	res += nums[i];
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> cnt(20001, 0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]+10000];
        }
        int add = 1;
        for (int i = 0; i < 20001; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (add) {
                    res += i-10000;
                }
                add ^= 1;
            }
        }
        return res;
    }
};