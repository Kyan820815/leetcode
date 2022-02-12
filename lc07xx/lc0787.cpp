//--- Q: 0787. Cheapest Flights Within K Stops

//--- method 1: dijkstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<array<int,2>>> rel(n);
        for (auto &flight: flights) {
            rel[flight[0]].push_back({flight[1], flight[2]});
        }
        vector<vector<int>> visit(n, vector<int>(k+1, INT_MAX));
        auto comp = [](const array<int,3> &a, const array<int,3> &b) {
            return a[1] > b[1];
        };
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(comp)> que(comp);
        for (int i = 0; i <= k; ++i) {
            visit[src][i] = 0;
        }
        que.push({src, 0, k});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int idx = now[0], cost = now[1], cnt = now[2];
            if (idx == dst) {
                return cost;
            }
            for (auto &node: rel[idx]) {
                int next = node[0], price = node[1];
                if (next == dst) {
                    if (visit[next][cnt] > cost+price) {
                        visit[next][cnt] = cost+price;
                        que.push({next, cost+price, cnt});
                    }
                } else if (cnt && visit[next][cnt-1] > cost+price) {
                    visit[next][cnt-1] = cost+price;
                    que.push({next, cost+price, cnt-1});
                }
            }
        }
        return -1;
    }
};