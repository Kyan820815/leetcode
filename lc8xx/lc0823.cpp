//--- Q: 823. Binary Trees With Factors

//--- method 1: dp iteration
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
    	unordered_map<int, long> dp;
        long M = 1e9+7, res = 0;
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i)
    	{
            dp[A[i]] = 1;
    		for (int j = 0; j < i; ++j)
    		{
                if (A[i] % A[j] == 0 && dp.count(A[i]/A[j]))
                {
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i]/A[j]]) % M;
                }
            }
            res = (res + dp[A[i]])%M;
    	}
    	return res;
    }
};