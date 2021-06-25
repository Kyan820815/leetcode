//--- Q: 1624. Largest Substring Between Two Equal Characters

//--- method 1: linear find
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> cnt(128, -1);
        int dis = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (cnt[s[i]] == -1) {
                cnt[s[i]] = i;
            } else if (i-cnt[s[i]]-1 > dis) {
                dis = i-cnt[s[i]]-1;
            }
        }
        return dis;
    }
};