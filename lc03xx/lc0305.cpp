//--- Q: 0305. Number of Islands II

//--- method 1: union by size
class Solution {
public:
    vector<int> parent;
    int cnt = 0;
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        parent.resize(m*n, -1);
        for (auto &position: positions) {
            int cidx = position[0]*n+position[1];
            if (parent[cidx] != -1) {
                res.push_back(cnt);
                continue;
            }
            int ap = findp(cidx);
            for (auto &dir: dirs) {
                int nr = position[0]+dir[0];
                int nc = position[1]+dir[1];

                int nidx = nr*n + nc;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || parent[nidx] == -1) {
                    continue;
                }
                int bp = findp(nidx);
                if (ap != bp) {
                    --cnt;
                    parent[ap] = bp;
                }
                ap = findp(cidx);
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] == -1) {
            ++cnt;
            return parent[now] = now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};