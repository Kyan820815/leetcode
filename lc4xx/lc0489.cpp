//--- Q: 489. Robot Room Cleaner

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
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    void cleanRoom(Robot& robot) {
        unordered_set<string> set;
        dfs(robot, 0, 0, 0, set);
    }
    void dfs(Robot& robot, int r, int c, int dir, unordered_set<string> &set)
    {
        robot.clean();
        for (int i = 0; i < 4; ++i)
        {
            int cur = (dir+i) % 4;
            int nr = r+dirs[cur][0];
            int nc = c+dirs[cur][1];
            string str = to_string(nr) + "," + to_string(nc);
            if (set.find(str) == set.end() && robot.move())
            {
                set.insert(str);
                dfs(robot, nr, nc, cur, set);
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
