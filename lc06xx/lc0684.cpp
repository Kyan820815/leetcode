//--- Q: 0684. Redundant Connection

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n, -1);
        for (auto &edge: edges) {
            int ap = findp(edge[0]-1);
            int bp = findp(edge[1]-1);
            if (ap != bp) {
                parent[ap] = bp;
            } else {
                return edge;
            }
        }
        return {};
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] == -1 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        for (auto &edge: edges) {
            rel[edge[0]-1].push_back(edge[1]-1);
            rel[edge[1]-1].push_back(edge[0]-1);
            ++deg[edge[0]-1];
            ++deg[edge[1]-1];
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }
        while (que.size()) {
            auto qsize = que.size();
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
        for (int i = n-1; i >= 0; --i) {
            if (deg[edges[i][0]-1] > 1 && deg[edges[i][1]-1] > 1) {
                return edges[i];
            }
        }
        return {};
    }
};