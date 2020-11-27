//--- Q: 305. Number of Islands II

//--- method 1: union by size
class Solution {
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parent(m*n, -1), res_vec, p_size(m*n, 0);
        vector<vector<int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};
        int res = 0;
        for (int i = 0; i < positions.size(); ++i) {
            int curp = positions[i][0] * n + positions[i][1];
            if (parent[curp] != -1) {
                res_vec.push_back(res);
                continue;
            }
            int curp_parent = findp(curp, parent);
            ++p_size[curp_parent];
            ++res;
            for (int k = 0; k < 4; ++k) {
                int ni = positions[i][0] + dir[k][0];
                int nj = positions[i][1] + dir[k][1];
                int nextp = ni*n + nj;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || parent[nextp] == -1) {
                    continue;
                }
                int curp_parent = findp(curp, parent);
                int nextp_parent = findp(nextp, parent);
                if (nextp_parent != curp_parent) {
                    if (p_size[nextp_parent] < p_size[curp_parent]) {
                        parent[nextp_parent] = curp_parent;
                        p_size[curp_parent] += p_size[nextp_parent];
                    } else {
                        parent[curp_parent] = nextp_parent;
                        p_size[nextp_parent] += p_size[curp_parent];
                    }
                    --res;
                }
            }
            res_vec.push_back(res);
        }
        return res_vec;
    }
    int findp(int now, vector<int> &parent) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] == -1 ? parent[now] = now : parent[now] = findp(parent[now], parent);
        }
    }
};