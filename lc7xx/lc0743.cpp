//--- Q: 743. Network Delay Time

//--- method 1: bfs with dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> nodeval(N+1, INT_MAX);
        vector<vector<int>> rel(N+1, vector<int>(N+1, -1));
        int res = 0;
        for (int i = 0; i < times.size(); ++i) {
            rel[times[i][0]][times[i][1]] = times[i][2];
        }
        nodeval[K] = 0;
        auto comp = [&nodeval](int a, int b) {
            return nodeval[a] > nodeval[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> que(comp);
        que.push(K);
        while (que.size()) {
            auto node = que.top();
            que.pop();
            int now = node;
            for (int i = 1; i <= N; ++i) {
                if (rel[now][i] != -1) {
                    nodeval[i] = min(nodeval[i], nodeval[now]+rel[now][i]);
                    que.push(i);
                    rel[now][i] = -1;
                }
                // or
                // if (rel[now][i] != -1 && nodeval[i] > nodeval[now]+rel[now][i]) {
                //     nodeval[i] = nodeval[now]+rel[now][i];
                //     que.push(i);
                // }
            }
        }
        for (int i = 1; i <= N; ++i) {
            res = max(res, nodeval[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};

//--- method 2: bfs with queue
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> nodeval(N+1, INT_MAX);
        vector<vector<int>> rel(N+1, vector<int>(N+1, -1));
        int res = 0;
        for (int i = 0; i < times.size(); ++i) {
            rel[times[i][0]][times[i][1]] = times[i][2];
        }
        nodeval[K] = 0;
        queue<int> que;
        que.push(K);
        while (que.size()) {
            auto node = que.front();
            que.pop();
            int now = node;
            for (int i = 1; i <= N; ++i) {
                if (rel[now][i] != -1 && nodeval[i] > nodeval[now] + rel[now][i]) {
                    nodeval[i] = nodeval[now]+rel[now][i];
                    que.push(i);
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            res = max(res, nodeval[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};

//--- method 3: Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < times.size(); ++j) {
                int u = times[j][0], v = times[j][1], w = times[j][2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};