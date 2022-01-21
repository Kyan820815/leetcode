//--- Q: 1059. All Paths from Source Lead to Destination

//--- method 1: dfs recursion
class Solution {
public:
    vector<vector<int>> rel;
    vector<int> visit;
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        rel.resize(n);
        visit.resize(n, -1);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
        }
        return dfs(source, destination);
    }
    int dfs(int now, int dst) {
        if (visit[now] != -1) {
            return visit[now];
        }
        if (!rel[now].size()) {
            return visit[now] = now == dst;
        }
        visit[now] = 0;
        for (auto &next: rel[now]) {
            if (!dfs(next, dst)) {
                return visit[now];
            }
        }
        return visit[now] = 1;
    }
};