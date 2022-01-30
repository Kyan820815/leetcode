//--- Q: 1189. Maximum Number of Balloons

//--- method 1: bucket sort
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26, 0);
        for (auto &ch: text) {
            ++cnt[ch-'a'];
        }
        int one = min(cnt['b'-'a'], min(cnt['a'-'a'], cnt['n'-'a']));
        int twice = min(cnt['l'-'a'], cnt['o'-'a']);
        return min(one, twice>>1);
    }
};