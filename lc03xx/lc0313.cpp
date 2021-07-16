//--- Q: 0313. Super Ugly Number

//--- method 1: dp iteration
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res = {1};
        vector<int> idx(primes.size(), 0);
        for (int i = 2; i <= n; ++i) {
            int minv = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                minv = min(minv, primes[j]*res[idx[j]]);
            }
            res.push_back(minv);
            for (int j = 0; j < primes.size(); ++j) {
                if (primes[j]*res[idx[j]] <= res.back()) {
                    ++idx[j];
                }
            }
        }
        return res.back();
    }
};