//--- Q: 1403. Minimum Subsequence in Non-Increasing Order

//--- method 1: bucket sort
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> val(101, 0);
        int sum = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ++val[nums[i]];
        }
        int now = 0;
        for (int i = 100; i >= 1 && now <= (sum>>1); --i) {
            while (val[i]-- && now <= (sum>>1)) {
                now += i;
                res.push_back(i);
            }
        }
        return res;
    }
};

//--- method 2: nlogn sort
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        int now = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
            res.push_back(nums[i]);
            now += nums[i];
            if (now > sum/2) {
                break;
            }
        }
        return res;
    }
};
