//--- Q: 2083. Substrings That Begin and End With the Same Letter

//--- method 1: add when face the character
class Solution {
public:
    using ll = long long;
    long long numberOfSubstrings(string s) {
        vector<int> cnt(26, 0);
        ll res = 0;
        for (auto &ch: s) {
            res += ++cnt[ch-'a'];
        }
        return res;
    }
};

//--- method 2: math calculation
class Solution {
public:
    using ll = long long;
    long long numberOfSubstrings(string s) {
        vector<int> cnt(26, 0);
        for (auto &ch: s) {
            ++cnt[ch-'a'];
        }
        ll res = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                res += (ll)(cnt[i]+1)*(cnt[i])/2;
            }
        }
        return res;
    }
};