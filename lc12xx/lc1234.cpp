//--- Q: 1234. Replace the Substring for Balanced String

//--- method 1: sliding window
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> cnt;
        for (auto ch: s) {
            ++cnt[ch];
        }
        int right = 0, left = 0, res = INT_MAX, n = s.size(), k = n/4;
        while (right < n) {
            --cnt[s[right]];
            while (left < n && cnt['Q'] <= k && cnt['W'] <= k && cnt['E'] <= k && cnt['R'] <= k) {
                res = min(res, right-left+1);
                ++cnt[s[left++]];
            }
            ++right;
        }
        return res;
    }
};