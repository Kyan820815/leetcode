//--- Q: 1043. Partition Array for Maximum Sum

//--- metho 1: O(n*K)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
    	int max_val = INT_MIN;
    	vector<int> dp(A.size(),-1);
    	for (int i = 0; i < A.size(); ++i)
    	{
    		if (i < K)
    		{
    			max_val = max(max_val, A[i]);
    			dp[i] = max_val*(i+1);
    		}
    		else
    		{
    			max_val = A[i];
    			for (int j = i-1; j >= i-K; --j)
    			{
    				max_val = max(max_val, A[j+1]);
    				dp[i] = max(dp[i], dp[j] + max_val*(i-j));
    			}
    		}
    	}
    	return dp.back();
    }
};