//--- Q: 1037. Valid Boomerang

//--- method 1: slope computation
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0], y1 = points[0][1];
        int x2 = points[1][0], y2 = points[1][1];
        int x3 = points[2][0], y3 = points[2][1];
        int left = (x1-x2)*(y2-y3), right = (x2-x3)*(y1-y2);
        return left != right;
    }
};