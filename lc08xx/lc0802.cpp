//--- Q: 0802. Find Eventual Safe States

//--- method 1: dfs recursion
class Solution {
public:
    vector<int> visit;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        visit.resize(n, -1);
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (visit[i] == -1) {
                dfs(i, graph);
            }
            if (visit[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
    int dfs(int now, vector<vector<int>> &graph) {
        if (!graph[now].size()) {
            return visit[now] = 1;
        }
        if (visit[now] != -1) {
            return visit[now];
        }
        visit[now] = 0;
        for (auto &next: graph[now]) {
            if (!dfs(next, graph)) {
                return visit[now];
            }
        }
        return visit[now] = 1;
    }
};