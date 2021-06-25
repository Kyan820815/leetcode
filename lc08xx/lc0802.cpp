//--- Q: 802. Find Eventual Safe States

//--- method 1: dfs recursion
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n, -1), res;
        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, visit)) {
                res.push_back(i);
            }
        }
        return res;
    }
    bool dfs(int now, vector<vector<int>>& graph, vector<int> &visit) {
        // if visit before, return directly
        if (visit[now] != -1) {
            return visit[now];
        }
        // set current value to 0, will be updated after dfs from this point
        visit[now] = 0;
        for (int i = 0; i < graph[now].size(); ++i) {
            if (!dfs(graph[now][i], graph, visit)) {
                return visit[now];
            }
        }
        return visit[now] = 1;
    }
};