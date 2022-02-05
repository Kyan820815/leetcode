//--- Q: 1848. Minimum Distance to the Target Element

//--- method 1: one direction search
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX, n = nums.size();
        for (int i = 0; i < n && res > abs(start-i); ++i) {
            if (nums[i] == target) {
                res = abs(i-start);
            }
        }
        return res;
    }
};

//--- method 2: two direction search from start
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX, n = nums.size(), i = 0;
        while (nums[max(0, start-i)] != target && nums[min(n-1, start+i)] != target) {
            ++i;
        }
        return i;
    }
};