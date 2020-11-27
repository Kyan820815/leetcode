//--- Q: 718. Maximum Length of Repeated Subarray

//--- method 1: dp iteration, better
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> dp(B.size(), 0);
        int res = INT_MIN;
        for (int i = 0; i < A.size(); ++i) {
            int now = 0, last = 0;
            for (int j = 0; j < B.size(); ++j) {
                last = dp[j];
                if (A[i] == B[j])
                    dp[j] = now+1;
                else
                    dp[j] = 0;
                res = max(res, dp[j]);
                now = last;
            }
        }
        return res;
    }
};

//--- method 2: dp iteration
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
    	int maxv = INT_MIN;
        vector<int> dp(B.size(), 0);
        for (int i = 0; i < A.size(); ++i)
        {
            vector<int> tmp(B.size());
            int j;
        	for (j = 0; j < B.size(); ++j)
        	{
        		if (A[i] == B[j])
        			tmp[j] = max(tmp[j], ((j == 0) ? 0 : dp[j-1]) + 1);
        	    maxv = max(maxv, tmp[j]);
        	}
            dp = tmp;
        }
        return maxv;
    }
};