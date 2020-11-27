//--- Q: 1057. Campus Bikes

//--- method 1: bucket sort
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<vector<pair<int, int>>> dist(2001);
        vector<int> res(n, -1), used(m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dis = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                dist[dis].push_back({i, j});
            }
        }
        for (int i = 1; i <= 2000; ++i) {
            if (dist.size()) {
                for (int j = 0; j < dist[i].size(); ++j) {
                    auto p = dist[i][j];
                    if (!used[p.second] && res[p.first] == -1) {
                        res[p.first] = p.second;
                        used[p.second] = true;
                    }
                }
            }
        }
        return res;
    }
};