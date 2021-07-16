//--- Q: 0310. Minimum Height Trees

//--- method 1: dfs recursion, my version
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (!edges.size()) {
            return {0};
        }
        queue<int> que;
        vector<int> res, deg(n, 0);
        vector<vector<int>> rel(n);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            rel[edge[1]].push_back(edge[0]);
            ++deg[edge[0]];
            ++deg[edge[1]];
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }
        while (que.size() && n > 2) {
            auto qsize = que.size();
            n -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rel[now]) {
                    if (--deg[next] == 1) {
                        que.push(next);
                    }
                }
            }
        }
        while (que.size()) {
            res.push_back(que.front());
            que.pop();
        };
        return res;
    }
};