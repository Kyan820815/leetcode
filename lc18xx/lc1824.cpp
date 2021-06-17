//--- Q: 1824. Minimum Sideway Jumps

//--- method 1: dijkstra + priority queue
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(), res = 0;
        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[2] > b[2];
        };
        vector<vector<int>> visit(4, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> que(comp);
        que.push({2,0,0});
        while (que.size()) {
            auto now = que.top();
            que.pop();
            int lane = now[0], idx = now[1], jump = now[2];
            if (idx == n-1) {
                return jump;
            }
            if (obstacles[idx+1] == lane) {
                for (int i = 1; i <= 3; ++i) {
                    if (i != lane && obstacles[idx] != i && visit[i][idx] > jump+1) {
                        visit[i][idx] = jump+1;
                        que.push({i,idx,jump+1});
                    }
                }
            } else {
                if (visit[lane][idx+1] > jump) {
                    visit[lane][idx+1] = jump;
                    que.push({lane, idx+1,jump});
                }
            }
        }
        return 0;
    }
};

//--- method 2: bfs + queue
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(), res = 0;
        vector<vector<int>> visit(4, vector<int>(n, INT_MAX));
        queue<pair<int,int>> que;
        que.push({2,0});
        visit[2][0] = 0;
        while (que.size()) {
            auto now = que.front();
            que.pop();
            int lane = now.first, idx = now.second;
            if (idx == n-1) {
                continue;
            }
            int jump = visit[lane][idx];
            if (obstacles[idx+1] == lane) {
                for (int i = 1; i <= 3; ++i) {
                    if (i != lane && obstacles[idx] != i && visit[i][idx] > jump+1) {
                        visit[i][idx] = jump+1;
                        que.push({i,idx});
                    }
                }
            } else {
                if (visit[lane][idx+1] > jump) {
                    visit[lane][idx+1] = jump;
                    que.push({lane, idx+1});
                }
            }
        }
        return min(visit[1][n-1], min(visit[2][n-1], visit[3][n-1]));
    }
};

//--- method 3: dp
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> dp = {1,0,1};
        for (auto &lane: obstacles) {
            if (lane > 0) {
                dp[lane-1] = 100000000;
            }
            for (int i = 0; i < 3; ++i) {
                if (i+1 != lane) {
                    dp[i] = min(dp[i], min(dp[(i+1)%3], dp[(i+2)%3])+1);
                }
            }
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};