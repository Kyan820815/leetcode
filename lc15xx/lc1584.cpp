//--- Q: 1584. Min Cost to Connect All Points

//--- method 1: union find / kruskal sort
class Solution {
public:
    vector<int> parent;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n, -1);
        vector<pair<int,pair<int,int>>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dis, {i, j}});
            }
        }
        sort(edges.begin(), edges.end(), [](const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b) {
            return a.first < b.first;
        });
        int res = 0;
        for (auto &edge: edges) {
            int ap = findp(edge.second.first);
            int bp = findp(edge.second.second);
            if (ap != bp) {
                if (-parent[ap] < -parent[bp]) {
                    swap(ap, bp);
                }
                parent[ap] += parent[bp];
                parent[bp] = ap;
                res += edge.first;
                if (parent[ap] == -n) {
                    break;
                }
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] < 0) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};

//--- method 2: union find / kruskal heap
class Solution {
public:
    vector<int> parent;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n, -1);
        vector<array<int, 3>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dis, i, j});
            }
        }
        make_heap(edges.begin(), edges.end(), greater<array<int, 3>>());
        int res = 0;
        while (edges.size()) {
            pop_heap(edges.begin(), edges.end(), greater<array<int, 3>>());
            array<int, 3> edge = edges.back();
            edges.pop_back();
            int ap = findp(edge[1]);
            int bp = findp(edge[2]);
            if (ap != bp) {
                if (-parent[ap] < -parent[bp]) {
                    swap(ap, bp);
                }
                parent[ap] += parent[bp];
                parent[bp] = ap;
                res += edge[0];
                if (parent[ap] == -n) {
                    break;
                }
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] < 0) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};

//--- method 3: union find / kruskal priority queue
class Solution {
public:
    vector<int> parent;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n, -1);
        vector<array<int, 3>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dis, i, j});
            }
        }
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> que(edges.begin(), edges.end());
        int res = 0;
        while (que.size()) {
            auto edge = que.top();
            que.pop();
            int ap = findp(edge[1]);
            int bp = findp(edge[2]);
            if (ap != bp) {
                if (-parent[ap] < -parent[bp]) {
                    swap(ap, bp);
                }
                parent[ap] += parent[bp];
                parent[bp] = ap;
                res += edge[0];
                if (parent[ap] == -n) {
                    break;
                }
            }
        }
        return res;
    }
    int findp(int now) {
        if (parent[now] == now) {
            return now;
        } else if (parent[now] < 0) {
            return now;
        } else {
            return parent[now] = findp(parent[now]);
        }
    }
};

//--- method 4: prim / priority queue
class Solution {
public:
    vector<int> parent;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), isVisit = 0, cur = 0, res = 0;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> que;
        vector<int> visit(n, 0);
        while (++isVisit < n) {
            visit[cur] = 1;
            for (int i = 0; i < n; ++i) {
                if (!visit[i]) {
                    que.push({abs(points[i][0]-points[cur][0]) + abs(points[i][1]-points[cur][1]), i});
                }
            }
            while (visit[que.top()[1]]) {
                que.pop();
            }
            res += que.top()[0];
            cur = que.top()[1];
        }
        return res;
    }
};