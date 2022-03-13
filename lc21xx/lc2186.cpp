//--- Q: 2186. Minimum Number of Steps to Make Two Strings Anagram II

//--- method 1: bucket
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (auto &ch: s) {
            ++cnt1[ch-'a'];
        }
        for (auto &ch: t) {
            ++cnt2[ch-'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            res += abs(cnt1[i]-cnt2[i]);
        }
        return res;
    }
};