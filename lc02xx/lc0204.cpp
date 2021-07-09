//--- Q: 0204. Count Primes

//--- method 1: sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        int limit = sqrt(n), res = 0;
        vector<int> prime(n, 0);
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) {
                ++res;
                if (i <= limit) {
                    for (int j = i; j < n; j+=i) {
                        prime[j] = 1;
                    }
                }
            }
        }
        return res;
    }
};