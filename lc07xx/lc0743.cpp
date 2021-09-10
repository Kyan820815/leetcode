//--- Q: 0743. Network Delay Time

//--- method 1: bfs with queue
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> rel(n, vector<int>(n, -1));
        for (auto &time: times) {
            rel[time[0]-1][time[1]-1] = time[2];
        }
        vector<int> visit(n, INT_MAX);
        queue<int> que;
        que.push(k-1);
        visit[k-1] = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (int i = 0; i < n; ++i) {
                    if (rel[now][i] != -1 && visit[now]+rel[now][i] < visit[i]) {
                        visit[i] = visit[now] + rel[now][i];
                        que.push(i);
                    }
                }
            }
        }
        int res = 0;
        for (auto &val: visit) {
            res = max(res, val);
        }
        return res == INT_MAX ? -1 : res;
    }
};


//--- method 2: dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        auto comp = [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> que(comp);
        vector<vector<int>> rel(n, vector<int>(n, -1));
        for (auto &time: times) {
            rel[time[0]-1][time[1]-1] = time[2];
        }
        vector<int> visit(n, 0);
        que.push({k-1,0});
        int sz = n;
        while (que.size()) {
            auto now = que.top();
            que.pop();
            if (visit[now.first]) {
                continue;
            }
            visit[now.first] = 1;
            if (!--sz) {
                return now.second;
            }
            auto id = now.first, val = now.second;
            for (int i = 0; i < n; ++i) {
                if (rel[id][i] != -1) {
                    que.push({i, val+rel[id][i]});
                }
            }
        }
        return -1;
    }
};
