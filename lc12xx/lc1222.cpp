//--- Q: 1222. Queens That Can Attack the King

//--- method 1: linear check
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<array<int,2>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        vector<vector<int>> res, chess(8, vector<int>(8, 0));
        for (auto &queen: queens) {
            chess[queen[0]][queen[1]] = 1;
        }
        for (auto &dir: dirs) {
            int r = king[0], c = king[1];
            while (valid(r+dir[0], c+dir[1]) && !chess[r+dir[0]][c+dir[1]]) {
                r += dir[0];
                c += dir[1];
            }
            if (valid(r+dir[0], c+dir[1]) && chess[r+dir[0]][c+dir[1]]) {
                res.push_back({r+dir[0], c+dir[1]});
            }
        }
        return res;
    }
    bool valid(int r, int c) {
        return r >= 0 && r < 8 && c >= 0 && c < 8;
    }
};