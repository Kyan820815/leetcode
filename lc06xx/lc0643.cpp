//--- Q: 0643. Maximum Average Subarray I

//--- method 1: linear processing
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, res;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i-k];
            res = max(res, sum);
        }
        return (double)res/k;
    }
};