//--- Q: 313. Super Ugly Number

//--- method 1: dp iteration
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(1,1);
        vector<int> prm(primes.size(), 0);

        while(dp.size() < n)
        {
        	int val = INT_MAX;
        	for (int i = 0; i < primes.size(); ++i)
        		val = min(val, dp[prm[i]]*primes[i]);
        	dp.push_back(val);
        	for (int i = 0; i < primes.size(); ++i)
        		while (dp[prm[i]]*primes[i] <= val)
        			++prm[i];
        }
        return dp.back();
    }
};