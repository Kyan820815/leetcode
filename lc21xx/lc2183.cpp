 //--- Q: 2183. Count Array Pairs Divisible by K

 //--- method 1: gcd
 class Solution {
public:
    using ll = long long;
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<ll,int> gcdmap;
        ll res = 0;
        for (auto &num: nums) {
            auto gcdi = gcd(num, k);
            for (auto &[gcdj, cnt]: gcdmap) {
                if ((ll)gcdi*gcdj%k == 0) {
                    res += cnt;
                }
            }
            ++gcdmap[gcdi];
        }
        return res;
    }
};

//--- method 2: gcd with factor map, optimization
class Solution {
public:
    using ll = long long;
    long long countPairs(vector<int>& nums, int k) {
        vector<array<int,2>> factor;
        int limit = sqrt(k);
        ll res = 0;
        for (int i = 1; i <= limit; ++i) {
            if (k%i == 0) {
                factor.push_back({i,0});
            }
            if (i*i != k) {
                factor.push_back({k/i,0});
            }
        }
        for (auto &num: nums) {
            auto gcdi = gcd(num, k);
            for (auto &[gcdj, cnt]: factor) {
                if ((ll)gcdi*gcdj%k == 0) {
                    res += cnt;
                }
                if (gcdi == gcdj) {
                    ++cnt;
                }
            }
        }
        return res;
    }
};