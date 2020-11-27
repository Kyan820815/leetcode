//--- Q: 1413. Minimum Value to Get Positive Step by Step Sum

//--- method 1: find minimum sum
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minv = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            minv = min(minv, sum);
        }
        return minv > 0 ? 1 : -minv+1;
    }
};

//--- method 2: add sum to 1 in each step
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1, sum = 1;
        for (int i = 0; i < nums.size(); ++i) {
            sum = nums[i] + sum;
            if (sum < 1) {
                res += 1-sum;
                sum = 1;
            }
        }
        return res;
    }
};