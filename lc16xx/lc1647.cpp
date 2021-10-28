//--- Q: 1647. Minimum Deletions to Make Character Frequencies Unique

//--- method 1: count times, O(n) space
class Solution {
public:
    int minDeletions(string s) {
        vector<int> times(26, 0), cnt(s.size()+1, 0);
        for (auto &ch: s) {
            ++times[ch-'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            ++cnt[times[i]];
        }
        for (int i = s.size(); i >= 1; --i) {
            if (cnt[i] > 1) {
                res += cnt[i]-1;
                cnt[i-1] += cnt[i]-1;
            }
        }
        return res;
    }
};

//--- method 2: count times, O(1) space
class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        vector<int> cnt(n+1, 0), times(26, 0);
        for (auto &ch: s) {
            ++times[ch-'a'];
        }
        for (int i = 0; i < 26; ++i) {
            ++cnt[times[i]];
        }
        int res = 0;
        for (int i = n; i >= 1; --i) {
            if (cnt[i]) {
                res += cnt[i]-1;
                cnt[i-1] += cnt[i]-1;
            }
        }
        return res;
    }
};