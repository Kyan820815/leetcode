//--- Q: 2021. Brightest Position on Street

//--- method 1: map operation
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> time;
        for (auto &light: lights) {
            ++time[light[0]-light[1]];
            --time[light[0]+light[1]+1];
        }
        int res = 0, resi, cnt = 0;;
        for (auto &t: time) {
            cnt += t.second;
            if (res < cnt) {
                res = cnt;
                resi = t.first;
            }
        }
        return resi;
    }
};