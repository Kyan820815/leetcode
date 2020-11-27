//--- Q: 684. Redundant Connection

//--- method 1: union find
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        for (int i = 0; i < edges.size(); ++i) {
            int ap = findp(edges[i][0], parent);
            int bp = findp(edges[i][1], parent);
            if (ap == bp)
                return edges[i];
            parent[ap] = bp;
        }
        return {};
    }
    int findp(int i, vector<int> &parent) {
        while (i != parent[i])
            i = parent[i];
        return i;
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> deg(n, 0);
        vector<vector<int>> edge(n);
        queue<int> que;
        for (int i = 0; i < edges.size(); ++i) {
            ++deg[edges[i][0]-1];
            ++deg[edges[i][1]-1];
            edge[edges[i][0]-1].push_back(edges[i][1]-1);
            edge[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1)
                que.push(i);
        }
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                --deg[now];
                for (int i = 0; i < edge[now].size(); ++i) {
                    if (--deg[edge[now][i]] == 1)
                        que.push(edge[now][i]);
                }
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (deg[edges[i][0]-1] > 1 && deg[edges[i][1]-1] > 1)
                return edges[i];
        }
        return {};
    }
};