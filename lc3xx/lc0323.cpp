//--- Q: 323. Number of Connected Components in an Undirected Graph

//--- method 1: dfs
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> rel(n);
        vector<int> visit(n, 0);
        int res = 0;
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
            rel[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                visit[i] = 1;
                dfs(i, rel, visit);
                ++res;
            }
        }
        return res;
    }
    void dfs(int now, vector<vector<int>> &rel, vector<int> &visit) {
        int n = visit.size();
        for (int i = 0; i < rel[now].size(); ++i) {
            if (!visit[rel[now][i]]) {
                visit[rel[now][i]] = 1;
                dfs(rel[now][i], rel, visit);
            }
        }
    }
};

//--- method 2: union find
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        int res = n;
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        
        for (int i = 0; i < edges.size(); ++i) {
            int ap = findP(edges[i][0], parent);
            int bp = findP(edges[i][1], parent);
            if (ap != bp) {
                --res;
                parent[ap] = bp;
            }
        }
        return res;
    }
    int findP(int i, vector<int> &parent) {
        while (i != parent[i])
            i = parent[i];
        return i;
    }
};