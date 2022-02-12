//--- Q: 2093. Minimum Cost to Reach City With Discounts

//--- method 1: dijkstra
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<int>> visit(n, vector<int>(discounts+1, INT_MAX));
        vector<vector<pair<int,int>>> rel(n);
        auto comp = [](const array<int,3> &a, const array<int,3> &b) {
            return a[2] > b[2];
        };
        priority_queue<array<int,3>, vector<array<int,3>>, decltype(comp)> que(comp);
        for (auto &highway: highways) {
            rel[highway[0]].push_back({highway[1], highway[2]});
            rel[highway[1]].push_back({highway[0], highway[2]});
        }
        for (int i = 0; i <= discounts; ++i) {
            visit[0][i] = 0;
        }
        que.push({0,discounts,0});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int idx = now[0], cnt = now[1], cost = now[2];
            if (idx == n-1) {
                return cost;
            }
            for (auto &node: rel[idx]) {
                int next = node.first, ncost = node.second;
                if (visit[next][cnt] > cost+ncost) {
                    visit[next][cnt] = cost+ncost;
                    que.push({next, cnt,cost+ncost});
                }
                if (cnt && visit[next][cnt-1] > cost+ncost/2) {
                    visit[next][cnt-1] = cost+ncost/2;
                    que.push({next, cnt-1,cost+ncost/2});
                }
            }
        }
        return -1;
    }
};