//--- Q: 1347. Minimum Number of Steps to Make Two Strings Anagram

//--- method 1: 1 vector
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt1[s[i]-'a'];
            --cnt1[t[i]-'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] < 0) {
                res -= cnt1[i];
            }
        }
        return res;
    }
};

//--- method 2: 2 vector
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt1[s[i]-'a'];
            ++cnt2[t[i]-'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += min(cnt1[i], cnt2[i]);
        }
        return s.size() - res;
    }
};
