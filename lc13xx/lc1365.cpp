//--- Q: 1365. How Many Numbers Are Smaller Than the Current Number

//--- method 1: bucket sort
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> bucket(101, 0);
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            ++bucket[nums[i]];
        }
        int cnt = 0;
        for (int i = 0; i <= 100; ++i) {
            if (bucket[i] > 0) {
                int tmp = bucket[i];
                bucket[i] = cnt;
                cnt += tmp;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            res.push_back(bucket[nums[i]]);
        }
        return res;
    }
};