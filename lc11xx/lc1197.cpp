//--- Q: 1197. Minimum Knight Moves

//--- method 1: dp solution
class Solution {
public:
    unordered_map<string, int> map;
    int minKnightMoves(int x, int y) {
        map["0_0"] = 0;
        return dp(abs(x), abs(y));
    }
    int dp(int x, int y) {
        string &&str = to_string(x) + "_" + to_string(y);
        if (map.find(str) != map.end()) {
            return map[str];
        }
        // (1,1), (2,0), (0,2)
        if (x+y == 2) {
            return 2;
        }
        return map[str] = min(dp(abs(x-1), abs(y-2)), dp(abs(x-2), abs(y-1))) + 1;
    }
};

//--- method 2: bfs
class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> dir = {{1,2}, {1,-2}, {-1, 2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};
        vector<vector<int>> visit(301, vector<int>(301, 0));
        queue<pair<int, int>> que;
        que.push({0, 0});
        visit[0][0] = 1;
        int res = 0;
        x = abs(x);
        y = abs(y);
        while (que.size()) {
            int qsize = que.size();
            for (int i = 0; i < qsize; ++i) {
                auto now = que.front();
                que.pop();
                if (now.first == x && now.second == y) {
                    return res;
                }
                for (int j = 0; j < 8; ++j) {
                    int nx = now.first + dir[j][0];
                    int ny = now.second + dir[j][1];
                    if (nx > 300 || ny > 300 || visit[abs(nx)][abs(ny)]) {
                        continue;
                    }
                    visit[abs(nx)][abs(ny)] = 1;
                    que.push({abs(nx), abs(ny)});
                }
            }
            ++res;
        }
        return -1;
    }
};