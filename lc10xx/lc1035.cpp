//--- Q: 1035. Uncrossed Lines

//--- method 1: dp, O(n^2) space
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = i && j ? dp[i-1][j-1] + 1 : 1;
                } else {
                    int left = j ? dp[i][j-1] : 0;
                    int right = i ? dp[i-1][j] : 0;
                    dp[i][j] = max(left, right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

//--- method 2: dp, O(n) space
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; ++i) {
            int last = 0;
            for (int j = 0; j < m; ++j) {
                int cur = dp[j];
                if (nums1[i] == nums2[j]) {
                    dp[j] = last+1;
                } else {
                    dp[j] = max(dp[j], j ? dp[j-1] : 0);
                }
                last = cur;
            }
        }
        return dp[m-1];
    }
};
