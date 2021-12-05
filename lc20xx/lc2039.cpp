//--- Q: 2039. The Time When the Network Becomes Idle

//--- method 1: dfs cound distance and math
class Solution {
public:
    vector<int> visit;
    vector<vector<int>> rel;
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        rel.resize(n);
        visit.resize(n, INT_MAX);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
        }
        visit[0] = 0;
        dfs(0);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            int cnt = visit[i]*2/patience[i];
            if (!cnt) {
                res = max(res, visit[i]*2);
            } else {
                int diff = (visit[i]*2)%patience[i] == 0 ? patience[i] : ((visit[i]*2)%patience[i]);
                res = max(res, visit[i]*4-diff);
            }
        }
        return res+1;
    }
    void dfs(int now) {
        for (auto &next: rel[now]) {
            if (visit[next] > visit[now]+1) {
                visit[next] = visit[now]+1;
                dfs(next);
            }
        }
    }
};