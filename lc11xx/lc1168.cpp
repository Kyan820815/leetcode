//--- Q: 1168. Optimize Water Distribution in a Village

//--- method 1: union find
class Solution {
public:
    vector<int> parent;
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        parent.resize(n+1, -1);
        for (int i = 0; i < n; ++i) {
            pipes.push_back({i+1, 0, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        int res = 0;
        for (int i = 0; n > 0; ++i) {
            int ap = findp(pipes[i][0]);
            int bp = findp(pipes[i][1]);
            if (ap != bp) {
                parent[ap] = bp;
                res += pipes[i][2];
                n--;
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else {
            return parent[now] = parent[now] < 0 ? now : findp(parent[now]);
        }
    }
};

//--- method 2: dijkstra
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<array<int,2>>> rel(n+1);
        for (int i = 0; i < pipes.size(); ++i) {
            rel[pipes[i][0]].push_back({pipes[i][1], pipes[i][2]});
            rel[pipes[i][1]].push_back({pipes[i][0], pipes[i][2]});
        }
        for (int i = 0; i < n; ++i) {
            rel[0].push_back({i+1, wells[i]});
            rel[i+1].push_back({0, wells[i]});
        }
        auto comp = [](const array<int,2> &a, const array<int,2> &b) {
            return a[1] > b[1];
        };
        priority_queue<array<int,2>, vector<array<int,2>>, decltype(comp)> que(comp);
        que.push({0,0});
        vector<int> costmap(n+1, INT_MAX), visit(n+1, 0);
        costmap[0] = 0;
        ++n;
        int res = 0;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int node = now[0], cost = now[1];
            if (visit[node]) {
                continue;
            }
            visit[node] = 1;
            res += cost;
            if (!--n) {
                return res;
            }
            for (auto &next: rel[node]) {
                int nextnode = next[0], ec = next[1];
                if (costmap[nextnode] > ec) {
                    costmap[nextnode] = ec;
                    que.push({nextnode, ec});
                }
            }
        }
        return -1;
    }
};
