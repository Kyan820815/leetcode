//--- Q: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves

//--- method 1: dfs recursion
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return dfs(0, nums.size()-1, nums, 3);
    }
    int dfs(int start, int end, vector<int> &nums, int k) {
        if (start == end) {
            return 0;
        }
        if (!k) {
            return abs(nums[end]-nums[start]);
        }
        return min(dfs(start+1, end, nums, k-1), dfs(start, end-1, nums, k-1));
    }
};

//--- method 2: iteration
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX, block = nums.size()-3;
        for (int i = 0; i+block-1 < nums.size(); ++i) {
            res = min(res, nums[i+block-1]-nums[i]);
        }
        return res == INT_MAX ? 0 : res;
    }
};