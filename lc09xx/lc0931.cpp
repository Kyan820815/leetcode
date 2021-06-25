//--- Q: Minimum Falling Path Sum

//--- method 1: dp, space O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
    	int n = A.size(), minVal = INT_MAX;;
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < A[0].size(); ++j)
        	{	
        		if (i != 0)
        			A[i][j] = A[i][j] + min(min((j > 0) ? A[i-1][j-1] : INT_MAX, A[i-1][j]),
        							 		(j+1 < n) ? A[i-1][j+1] : INT_MAX);
        		if (i == n-1)
    				minVal = min(minVal, A[i][j]);
        	}
        }
        return minVal;
    }
};

//--- method 2: dp, space O(n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<int> dp(A.size(), 0);
        int row = A.size(), col = A[0].size(), res = INT_MAX;
        for (int i = 0; i < row; ++i) {
            vector<int> tmp(dp.size());
            for (int j = 0; j < col; ++j) {
                int left = (j-1 >= 0) ? dp[j-1] : INT_MAX;
                int right = (j+1 < col) ? dp[j+1] : INT_MAX;
                tmp[j] = min(left, min(dp[j], right)) + A[i][j];
                if (i == row-1)
                    res = min(res, tmp[j]);
            }
            dp = tmp;
        }
        return res;
    }
};