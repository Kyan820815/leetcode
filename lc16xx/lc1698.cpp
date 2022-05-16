//--- Q: 1698. Number of Distinct Substrings in a String

//--- method 1: rolling hash
class Solution {
public:
    using ll = long long;
    int countDistinct(string s) {
        int n = s.size(), mod = 1e9+7, res = 1;
        ll shash = 0, base = 1;
        for (int i = 0; i+1 < n; ++i) {
            shash = (shash*26 + s[i]-'a')%mod;
            unordered_set<int> set = {(int)shash};
            base = base*26 % mod;
            for (ll j = i+1, hash = shash; j < n; ++j) {
                hash = (hash*26%mod - base*(s[j-i-1]-'a')%mod + mod + s[j]-'a') % mod;
                set.insert(hash);
            }
            res += set.size();
        }
        return res;
    }
};