//--- Q: 1854. Maximum Population Year

//--- method 1: counting
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> cnt(101, 0);
        for (auto &log: logs) {
            ++cnt[log[0]-1950];
            --cnt[log[1]-1950];
        }
        int resy = -1, maxc = 0, curc = 0;
        for (int i = 0; i <= 100; ++i) {
            curc += cnt[i];
            if (curc > maxc) {
                maxc = curc;
                resy = i;
            }
        }
        return resy+1950;
    }
};