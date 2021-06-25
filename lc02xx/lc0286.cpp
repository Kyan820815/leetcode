//--- Q: 286. Walls and Gates

//--- method 1: bfs
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (!rooms.size()) {
            return;
        }
        int row = rooms.size(), col = rooms[0].size();
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<int> que;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (rooms[i][j] == 0) {
                    que.push(i*col+j);
                }
            }
        }
        int res = 0;
        while (que.size()) {
            int qsize = que.size();
            ++res;
            for (int k = 0; k < qsize; ++k) {
                auto now = que.front();
                int r = now/col, c = now%col;
                que.pop();
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dir[i][0], nc = c + dir[i][1];
                    if (nr < 0 || nr >= row || nc < 0 || nc >= col || rooms[nr][nc] != INT_MAX) {
                        continue;
                    }
                    rooms[nr][nc] = res;
                    que.push(nr*col + nc);
                }
            }
           
        }
    }
};
