//--- Q: 221. Maximal Square

//--- method 1: dp iteration, O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if (matrix.size() == 0) return 0;
     	int row = matrix.size(), col = matrix[0].size();
     	int max_len = INT_MIN, pre;
     	vector<int> dp(col, 0);

     	for (int i = 0; i < row; ++i)
     	{
     		for (int j = 0; j < col; ++j)
     		{
     			if (matrix[i][j] == '0')
     			{
     				pre = dp[j];
     				dp[j] = 0;
     			}
     			else if (i == 0 || j == 0)
     			{
     				pre = dp[j];
     				dp[j] = 1;
     			}
     			else
     			{
     				int tmp = dp[j];
     				dp[j] = min(pre, min(dp[j-1], dp[j])) + 1;
     				pre = tmp;
     			}
     			if (dp[j] > max_len)
     				max_len = dp[j];
     		}
     	}
     	return max_len*max_len;
    }
};

//--- method 2: dp iteration, O(n^2)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if (matrix.size() == 0) return 0;
     	int row = matrix.size(), col = matrix[0].size();
     	int max_len = INT_MIN;
     	vector<vector<int>> dp(row, vector<int>(col, 0));

     	for (int i = 0; i < row; ++i)
     	{
     		for (int j = 0; j < col; ++j)
     		{
     			if (matrix[i][j] == '0')
     				dp[i][j] = 0;
     			else if (i == 0 || j == 0)
     				dp[i][j] = 1;
     			else
     				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
     			if (dp[i][j] > max_len)
     				max_len = dp[i][j];
     		}
     	}
     	return max_len*max_len;
    }
};