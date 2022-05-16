//--- Q: 2101. Detonate the Maximum Bombs

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> rel;
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        rel.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                double dis = sqrt(pow(bombs[i][0]-bombs[j][0],2) + pow(bombs[i][1]-bombs[j][1],2));
                if (dis <= bombs[i][2]) {
                    rel[i].push_back(j);
                }
                if (dis <= bombs[j][2]) {
                    rel[j].push_back(i);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            vector<int> visit(n, 0);
            dfs(i, cnt, visit);
            res = max(res, cnt);
        }
        return res;
    }
    void dfs(int idx, int &cnt, vector<int> &visit) {
        ++cnt;
        visit[idx] = 1;
        for (auto &next: rel[idx]) {
            if (!visit[next]) {
               dfs(next, cnt, visit);
            }
        }
    }
};