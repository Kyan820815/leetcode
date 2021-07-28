//--- Q: 0486. Predict the Winner

//--- method 1: dfs recursion
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(0, nums.size()-1, nums, dp) >= 0;
    }
    int dfs(int start, int end, vector<int> &nums, vector<vector<int>> &dp) {
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        if (start == end) {
            return dp[start][end] = nums[start];
        }
        return dp[start][end] = max(nums[start]-dfs(start+1,end,nums,dp), 
                                    nums[end]-dfs(start,end-1,nums,dp));
    }
};

//--- method 2: dp iteration
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    dp[i][j] = nums[i];
                } else {
                    dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1] >= 0;
    }
};

//--- method 3: dp iteration, O(n) space
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    dp[j] = nums[i];
                } else {
                    dp[j] = max(nums[i]-dp[j], nums[j]-dp[j-1]);
                }
            }
        }
        return dp[n-1] >= 0;
    }
};