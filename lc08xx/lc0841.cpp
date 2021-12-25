//--- Q: 0841. Keys and Rooms

//--- method 1: dfs
class Solution {
public:
    vector<int> visit;
    int n;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        visit.resize(n, 0);
        dfs(0, rooms);
        return !n;
    }
    void dfs(int now, vector<vector<int>> &rooms) {
        visit[now] = 1;
        --n;
        for (auto &next: rooms[now]) {
            if (!visit[next]) {
                dfs(next, rooms);
            }
        }
    }
};

//--- method 2: bfs
class Solution {
public:
    int res = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visit(n, 0);
        queue<int> que;
        que.push(0);
        visit[0] = 1;
        while (que.size()) {
            auto qsize = que.size();
            n -= qsize;
            while (qsize--) {
                auto now = que.front();
                que.pop();
                for (auto &next: rooms[now]) {
                    if (!visit[next]) {
                        visit[next] = 1;
                        que.push(next);
                    }
                }
            }
        }
        return !n;
    }
};