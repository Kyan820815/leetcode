//--- Q: 1232. Check If It Is a Straight Line

//--- method 1: math transformation
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double specx = coordinates[1][0]-coordinates[0][0];
        double specy = coordinates[1][1]-coordinates[0][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            double nowx = coordinates[i][0]-coordinates[i-1][0];
            double nowy = coordinates[i][1]-coordinates[i-1][1];
            if (nowx*specy != nowy*specx) {
                return false;
            }
        }
        return true;
    }
};