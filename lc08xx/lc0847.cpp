//--- Q: 0847. Shortest Path Visiting All Nodes

//--- method 1: dijkstra
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), res = INT_MAX, all = (1<<n)-1;
        vector<vector<int>> cost(n, vector<int>(all+1, INT_MAX));
        auto comp = [](const array<int,3> &a, array<int,3> &b) {
            return a[2] > b[2];
        };
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(comp)> que(comp);
        for (int i = 0; i < n; ++i) {
            cost[i][1<<i] = 0;
            que.push({i,1<<i,0});
        }
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int node = now[0], state = now[1], nc = now[2];
            if (state == all) {
                return nc;
            }
            for (auto &next: graph[node]) {
                if ((state>>next) & 1) {
                    if (cost[next][state] > nc+1) {
                        cost[next][state] = nc+1;
                        que.push({next,state,cost[next][state]});
                    }
                } else {
                    int nstate = state | (1<<next);
                    if (cost[next][nstate] > nc+1) {
                        cost[next][nstate] = nc+1;
                        que.push({next,nstate,cost[next][nstate]});
                    }
                }
            }
        }
        return -1;
    }
};

//--- method 2: bfs
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), res = INT_MAX, all = (1<<n)-1;
        vector<vector<int>> cost(n, vector<int>(all+1, INT_MAX));
        queue<array<int,3>, vector<array<int,3>>, decltype(comp)> que(comp);
        for (int i = 0; i < n; ++i) {
            cost[i][1<<i] = 0;
            que.push({i,1<<i,0});
        }
        while (que.size()) {
            int qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
            }
            auto now = que.top();
            que.pop();
            int node = now[0], state = now[1], nc = now[2];
            for (auto &next: graph[node]) {
                if ((state>>next) & 1) {
                    if (cost[next][state] > nc+1) {
                        cost[next][state] = nc+1;
                        que.push({next,state,cost[next][state]});
                    }
                } else {
                    int nstate = state | (1<<next);
                    if (cost[next][nstate] > nc+1) {
                        cost[next][nstate] = nc+1;
                        que.push({next,nstate,cost[next][nstate]});
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            res = min(res, cost[i][all]);
        }
        return res;
    }
};
 