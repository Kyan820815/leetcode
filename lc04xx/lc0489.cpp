//--- Q: 0489. Robot Room Cleaner

//--- method 1: dfs with dynamic diretion
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

//--- method 1: dfs
class Solution {
public:
    unordered_set<string> visit;
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    void cleanRoom(Robot& robot) {
        visit.insert("0_0");
        dfs(0, 0, 0, robot);
    }
    void dfs(int r, int c, int d, Robot& robot) {
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            auto nd = (d+i) % 4;
            auto nr = r + dirs[nd][0], nc = c + dirs[nd][1];
            string tag = to_string(nr) + "," + to_string(nc);
            if (visit.find(tag) == visit.end() && robot.move()) {
                visit.insert(tag);
                dfs(nr, nc, nd, robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
};