//--- Q: 2156. Find Substring With Given Hash Value

//--- method 1: sliding window
class Solution {
public:
    using ll = long long;
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        ll cval = 0, pval = 1;
        for (int i = n-k; i < n; ++i) {
            cval = (cval + ((s[i]-'a')+1)*pval) % modulo;
            pval = (pval*power) % modulo;
        }
        int start;
        if (cval == hashValue) {
            start = n-k;
        }
        for (int i = n-k-1; i >= 0; --i) {
            cval = ((cval*power+((s[i]-'a')+1))%modulo - ((s[i+k]-'a')+1)*pval%modulo + modulo) % modulo;
            if (cval == hashValue) {
                start = i;
            }
        }
        return s.substr(start, k);
    }
};