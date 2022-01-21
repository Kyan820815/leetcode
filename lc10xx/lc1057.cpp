//--- Q: 1057. Campus Bikes

//--- method 1: ordered map
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<int> res(n, -1), used(m, 0);
        map<int, vector<pair<int,int>>> map;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dis = abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                map[dis].push_back({i,j});
            }
        }
        int cnt = 0;
        for (auto &node: map) {
            for (auto &p: node.second) {
                if (res[p.first] != -1 || used[p.second]) {
                    continue;
                }
                res[p.first] = p.second;
                used[p.second] = 1;
                ++cnt;
            }
            if (cnt == n) {
                break;
            }
        }
        return res;
    }
};

//--- method 2: bucket sort
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        vector<int> res(n, -1), used(m, 0);
        vector<vector<pair<int,int>>> map(2001);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dis = abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
                map[dis].push_back({i,j});
            }
        }
        int cnt = 0;
        for (auto &node: map) {
            for (auto &p: node) {
                if (res[p.first] != -1 || used[p.second]) {
                    continue;
                }
                res[p.first] = p.second;
                used[p.second] = 1;
                ++cnt;
            }
            if (cnt == n) {
                break;
            }
        }
        return res;
    }
};