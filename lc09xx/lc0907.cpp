//--- Q: 907. Sum of Subarray Minimums

//--- method 1: backward search to find the first index greater than cur
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0, M = 1e9+7;
        vector<int> dp(A.size(), 0);
        res = dp[0] = A[0];
        for (int i = 1; i < A.size(); ++i)
        {
        	if (A[i] >= A[i-1])
        		dp[i] = (dp[i-1] + A[i]) % M;
        	else
        	{
        		int cur = A[i], idx = i-1;
        		while (idx >= 0 && cur < A[idx])
        			--idx;
        		dp[i] = (((idx == -1) ? 0 : dp[idx]) + (i-idx) * cur) % M;
        	}
        	res = (res + dp[i]) % M;
        }
        return res;
    }
}

//--- method 2: using increasing monotone stack, better
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0, M = 1e9+7;
        vector<int> dp(A.size(), 0);
        stack<int> sk;
        sk.push(-1);
        for (int i = 0; i < A.size(); ++i)
        {
        	int cur = A[i];
        	while (sk.top() != -1 && cur < A[sk.top()])
        		sk.pop();
        	dp[i] = (i-sk.top()) * cur + ((sk.top() != -1) ? dp[sk.top()] : 0);
        	res = (res + dp[i]) % M;
        	sk.push(i);
        }
        return res;
    }
};
