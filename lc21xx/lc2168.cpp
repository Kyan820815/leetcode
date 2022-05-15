//--- Q: 2168. Unique Substrings With Equal Digit Frequency

//--- method 1: brute force
class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        unordered_set<string> set;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(10);
            for (int j = i; j < n; ++j) {
                ++cnt[s[j]-'0'];
                int prev = 0, valid = 1;
                for (int k = 0; k < 10; ++k) {
                    if (cnt[k]) {
                        if (prev && cnt[k] != prev) {
                            valid = 0;
                            break;
                        }
                        prev = cnt[k];
                    }
                }
                if (valid) {
                    set.insert(s.substr(i, j-i+1));
                }
            }
        }
        return set.size();
    }
};

//--- method 2: rolling hash
class Solution {
public:
    using ll = long long;
    int equalDigitFrequency(string s) {
        int n = s.size(), mod = 1e9+7;
        unordered_set<int> set;
        for (int i = 0; i < n; ++i) {
            int unique = 0, maxcnt = 0;
            ll val = 0;
            vector<int> cnt(10);
            for (int j = i; j < n; ++j) {
                unique += ++cnt[s[j]-'0'] == 1;
                maxcnt = max(maxcnt, cnt[s[j]-'0']);
                val = (val*11 + s[j]-'0'+1) % mod;
                if (unique * maxcnt == j-i+1) {
                    set.insert(val);
                }
            }
        }
        return set.size();
    }
};