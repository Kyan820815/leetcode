//--- Q: 743. Network Delay Time

//--- method 1: bfs with dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> val(n, vector<int>(n, -1));
        vector<int> dist(n, INT_MAX);
        for (auto &time: times) {
            val[time[0]-1][time[1]-1] = time[2];
        }
        auto comp = [](pair<int,int> &a, pair<int,int> &b){
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        int res = 0;
        que.push({k-1,0});
        dist[k-1] = 0;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int node = now.first, weight = now.second;
            for (int i = 0; i < val[node].size(); ++i) {
                if (val[node][i] != -1) {
                    int next_weight = weight + val[node][i];
                    if (next_weight < dist[i]) {
                        dist[i] = next_weight;
                        que.push({i,next_weight});
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            res = max(res, dist[i]);
        }
        return res == INT_MAX ? -1 :res;
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