//--- Q: 1197. Minimum Knight Moves

//--- method 1: dp solution
class Solution {
public:
    unordered_map<string,int> visit;
    int minKnightMoves(int x, int y) {
        return dfs(abs(x), abs(y));
    }
    int dfs(int x, int y) {
        string tag = to_string(x)+","+to_string(y);
        if (visit.find(tag) != visit.end()) {
            return visit[tag];
        }
        if (!x && !y) {
            return 0;
        } else if (x + y == 2) {
            return 2;
        }
        return visit[tag] = min(dfs(abs(x-2), abs(y-1)), dfs(abs(x-1), abs(y-2)))+1;
    }
};

//--- method 2: bfs
class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<int>> visit(301, vector<int>(301, 0));
        queue<pair<int,int>> que;
        vector<vector<int>> dirs = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1}};
        int res = 0;
        x = abs(x), y = abs(y);
        que.push({0,0});
        visit[0][0] = 1;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                if (now.first == x && now.second == y) {
                    return res;
                }
                que.pop();
                for (auto &dir: dirs) {
                    int nr = abs(now.first+dir[0]);
                    int nc = abs(now.second+dir[1]);
                    if (nr > 300 || nc > 300 || visit[nr][nc]) {
                        continue;
                    }
                    visit[nr][nc] = 1;
                    que.push({nr,nc});
                }
            }
            ++res;
        }
        return -1;
    }
};