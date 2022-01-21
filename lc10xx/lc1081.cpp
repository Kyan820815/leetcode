//--- Q: 1081. Smallest Subsequence of Distinct Characters

//--- method 1: stack iteration
class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        vector<int> cnt(26, 0), used(26, 0);
        for (auto &ch: s) {
            ++cnt[ch-'a'];
        }
        for (auto &ch: s) {
            --cnt[ch-'a'];
            if (used[ch-'a']) {
                continue;
            }
            while (res.size() && res.back() > ch && cnt[res.back()-'a']) {
                used[res.back()-'a'] = 0;
                res.pop_back();
            }
            res += ch;
            used[ch-'a'] = 1;
        }
        return res;
    }
};