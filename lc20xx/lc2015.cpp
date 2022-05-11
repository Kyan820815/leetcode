//--- Q: 2015. Average Height of Buildings in Each Segment

//--- method 1: find interval
class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        map<int, pair<int,int>> m;
        for (auto &building: buildings) {
            m[building[0]].first += building[2];
            ++m[building[0]].second;
            m[building[1]].first -= building[2];
            --m[building[1]].second;
        }
        vector<vector<int>> res;
        int last = -1, cnt = 0, h = 0;
        for (auto &[dis, info]: m) {
            if (last != -1 && cnt) {
                if (res.size() && res.back()[2] == h/cnt && res.back()[1] == last) {
                    res.back()[1] = dis;
                } else {
                    res.push_back({last, dis, h/cnt});
                }
            }
            last = dis;
            h += info.first;
            cnt += info.second;
        }
        return res;
    }
};