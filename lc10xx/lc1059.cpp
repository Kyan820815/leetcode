//--- Q: 1059. All Paths from Source Lead to Destination

//--- method 1: dfs recursion
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visit(n, -1);
        vector<vector<int>> rel(n);
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
        }
        return dfs(source, rel, visit, destination);
    }
    int dfs(int now, vector<vector<int>> &rel, vector<int> &visit, int dst) {
        if (visit[now] != -1) {
            return visit[now];
        }
        if (!rel[now].size()) {
            return visit[now] = (now==dst);
        }
        visit[now] = 0;
        for (int i = 0; i < rel[now].size(); ++i) {
            if (!dfs(rel[now][i], rel, visit, dst)) {
                return visit[now];
            }
        }
        return visit[now] = 1;
    }
};

//--- method 1-2: dfs recursion
class Solution {
public:
    vector<int> visit;
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> rel(n);
        visit.resize(n, 0);
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
        }
        return dfs(rel, source, destination);
    }
    bool dfs(vector<vector<int>> &rel, int now, int dst) {
        if (!rel[now].size()) {
            return now == dst;
        }
        visit[now] = 1;
        bool find = true;
        for (int i = 0; i < rel[now].size(); ++i) {
            if (!visit[rel[now][i]]) {
                find &= dfs(rel, rel[now][i], dst);
            } else {
                return false;
            }
        }
        visit[now] = 0;
        return find;
    }
};

//--- method 2: bfs
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visit(n, 0);
        vector<vector<int>> rel(n);
        for (int i = 0; i < edges.size(); ++i) {
            rel[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int> que{{source}};
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                visit[now] = 2;
                if (!rel[now].size()) {
                    return now == destination && !que.size();
                }
                for (int j = 0; j < rel[now].size(); ++j) {
                    if (visit[rel[now][j]] == 0) {
                        visit[rel[now][j]] = 1;
                        que.push(rel[now][j]);
                    } else if (visit[rel[now][j]] == 2){
                        return false;
                    }
                }
            }
        }
        return false;
    }
};