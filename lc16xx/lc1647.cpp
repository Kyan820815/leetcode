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
        vector<int> times(26, 0), cnt(s.size()+1, 0);
        for (auto &ch: s) {
            ++times[ch-'a'];
        }
        sort(times.begin(), times.end());
        int res = 0, now_feq = times[25];
        for (int i = 24; i >= 0; --i) {
            if (!times[i]) {
                continue;
            }
            if (times[i] >= now_feq) {
                if (now_feq) {
                    --now_feq;
                }
                res += times[i]-now_feq;
            } else {
                now_feq = times[i];
            }
        }
        return res;
    }
};