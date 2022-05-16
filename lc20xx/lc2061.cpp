//--- Q: 2061. Number of Spaces Cleaning Robot Cleaned

//--- method 1: dfs
class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int res = 0, row, col;
    int numberOfCleanRooms(vector<vector<int>>& room) {
        row = room.size(), col = room[0].size();
        dfs(0,0,0,room);
        return res;
    }
    void dfs(int r, int c, int d, vector<vector<int>> &room) {
        if (!room[r][c]) {
            ++res;
            room[r][c] = d+2;
        } else if (room[r][c] == d+2) {
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nd = (i+d)%4;
            int nr = r+dirs[nd][0];
            int nc = c+dirs[nd][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || room[nr][nc] == 1) {
                continue;
            }
            dfs(nr, nc, nd, room);
            break;
        }
    }
};