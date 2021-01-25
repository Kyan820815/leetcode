//--- Q: 1041. Robot Bounded In Circle

//--- method 1: find direction and position
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, idx = 0;
        vector<vector<int>> dir = {{0,1}, {-1,0}, {0,-1}, {1,0}};
        for (int i = 0; i < instructions.size(); ++i) {
            if (instructions[i] == 'L') {
                idx = (idx + 1) % 4;
            } else if (instructions[i] == 'R') {
                idx = (idx + 3) % 4;
            } else {
                x += dir[idx][0];
                y += dir[idx][1];
            }
        }
        return !x && !y || idx;
    }
};