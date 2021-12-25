//--- Q: 0874. Walking Robot Simulation

//--- method 1: find current direction and move
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int r = 0, c = 0, dir = 0, res = 0;
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        unordered_map<int, unordered_set<int>> map;
        for (auto &obstacle: obstacles) {
            map[obstacle[0]].insert(obstacle[1]);
        }
        for (auto &command: commands) {
            if (command == -1) {
                dir = (dir+1)%4;
            } else if (command == -2) {
                dir = (dir+3)%4;
            } else {
                for (int i = 0; i < command; ++i) {
                    r += dirs[dir][0];
                    c += dirs[dir][1];
                    if (map.find(r) != map.end() && map[r].find(c) != map[r].end()) {
                        r -= dirs[dir][0];
                        c -= dirs[dir][1];
                        break;
                    }
                    res = max(res, r*r+c*c);
                }
            }
        }
        return res;
    }
};