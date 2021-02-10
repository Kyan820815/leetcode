//--- Q: 1557. Minimum Number of Vertices to Reach All Nodes

//--- method 1: find node without in-degree
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0), res;
        for (auto &edge: edges) {
            ++deg[edge[1]];
        }
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};

//--- follow up with cyclic graph
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        n = 8, edges = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,4},{7,6}};
        vector<int> deg(n, 0), visit(n, 0), res;
        vector<vector<int>> rel(n);
        for (auto &edge: edges) {
            rel[edge[0]].push_back(edge[1]);
            ++deg[edge[1]];
        }
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                res.push_back(i);
                visit[i] = 1;
                dfs(i, visit, rel);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                visit[i] = 1;
                res.push_back(i);
                dfs(i, visit, rel);
            }
        }
        return res;
    }
    void dfs(int i, vector<int> &visit, vector<vector<int>> &rel) {
        for (auto &neib: rel[i]) {
            if (!visit[neib]) {
                visit[neib] = 1;
                dfs(neib, visit, rel);
            }
        }
    }
};