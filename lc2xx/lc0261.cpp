//--- Q: 261. Graph Valid Tree

//--- method 1: union find
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); ++i) {
            int ap = findP(edges[i][0], parent);
            int bp = findP(edges[i][1], parent);
            if (ap != bp) {
                parent[ap] = bp;
            } else {
                return false;
            }
        }
        return edges.size() == n-1;
    }
    int findP(int now, vector<int> &parent) {
        while (now != parent[now]) {
            now = parent[now];
        }
        return now;
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> rel(n);
        vector<int> deg(n, 0);
        int node = n;
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
            rel[edges[i][1]].push_back(edges[i][0]);
            ++deg[edges[i][0]];
            ++deg[edges[i][1]];
        }
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                int now = que.front();
                que.pop();
                --n;
                for (int j = 0; j < rel[now].size(); ++j) {
                    if (--deg[rel[now][j]] == 1) {
                        que.push(rel[now][j]);
                    }
                }
            }
        }
        return n <= 1 && edges.size() == node-1;
    }
};
