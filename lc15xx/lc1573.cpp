//--- Q: 1573. Number of Ways to Split a String

//--- method 1: find interval, two pass
# define ll long long
class Solution {
public:
    int numWays(string s) {
        ll res = 1, n = s.size();
        int cnt = 0, total = 0, mod = 1e9+7;
        for (auto &ch: s) {
            total += ch == '1';
        }
        if (!total) {
            return ((n-1)*(n-2)/2)%mod;
        }
        if (total%3 != 0) {
            return 0;
        }
        int times = total/3, last = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                int ones = 0, cur = i;
                for (; i < s.size() && ones != times; ++i) {
                    ones += (s[i] == '1');
                }
                if (++cnt > 1) {
                    res = (res * (cur-last)) % mod;
                }
                last = --i;
            }
        }
        return res;
    }
};

//--- method 2: record index of 1, one pass
# define ll long long
class Solution {
public:
    int numWays(string s) {
        ll n = s.size();
        int cnt = 0, total = 0, mod = 1e9+7;
        vector<int> ones;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++total;
                ones.push_back(i);
            }
        }
        if (!total) {
            return ((n-1)*(n-2)/2)%mod;
        }
        if (total%3 != 0) {
            return 0;
        }
        int sz = total/3;
        return (ll)(ones[sz]-ones[sz-1]) * (ll)(ones[2*sz]-ones[2*sz-1]) % mod;
    }
};