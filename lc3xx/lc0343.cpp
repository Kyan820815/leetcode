//--- Q: 343. Integer Break

//--- method 1-1: dp iteration, O(n^2)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
        	int l_max = INT_MIN;
        	for (int j = 1; j < i; ++j)
        		l_max = max(max(dp[i-j] * j, (i-j)*j), l_max);
        	dp[i] = l_max;
        }
        return dp[n];
    }
};

//--- method 1-2: dp iteration, O(n)
class Solution {
public:
    int integerBreak(int n) {
    	if (n < 4) return n-1;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] dp[2] = 1;
        dp[3] = 2; dp[4] = 4;

        for (int i = 5; i <= n; ++i)
        	dp[i] = 3*max(dp[i-3], i-3);
        return dp[n];
    }
};


//--- method 2: math solution
class Solution {
public:
    int integerBreak(int n) {
    	if (n < 4) return n-1;
        int res = 1;
        while(n > 4)
        {
        	res *= 3;
        	n -= 3;
        }
        return res*n;
    }
};