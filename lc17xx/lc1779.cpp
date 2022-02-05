//--- Q: 1779. Find Nearest Point That Has the Same X or Y Coordinate

//--- method 1: linear find
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = INT_MAX, idx = -1;
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                int dis = abs(x-points[i][0]) + abs(y-points[i][1]);
                if (res > dis) {
                    res = dis;
                    idx = i;
                }
            }
        }
        return idx;
    }
};