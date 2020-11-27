//--- Q: 204. Count Primes

//--- method 1: sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+1, 0);
        int res = 0, target = sqrt(n);
        for (int i = 2; i < n; ++i)
        {
        	if (!prime[i])
        	{
        		++res;
                if (i <= target)
                {
            		int now = i;
            		for (int j = 1; j*i < n; ++j)
            			prime[j*i] = 1;
                }
        	}
        }
        return res;
    }
};