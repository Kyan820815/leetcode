//--- Q: 1041. Robot Bounded In Circle

//--- method 1: find direction and position
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int x = 0, y = 0, dir = 0;
        for (auto &ch: instructions) {
            if (ch == 'G') {
                x += dirs[dir][0];
                y += dirs[dir][1];
            } else if (ch == 'L') {
                dir = (dir+1)%4;
            } else {
                dir = (dir+3)%4;
            }
        }
        return !x && !y || dir;
    }
};