//--- Q: 0452. Minimum Number of Arrows to Burst Balloons

//--- method 1: sort the second term
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int end = points[0][1], res = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (end < points[i][0]) {
                end = points[i][1];
                ++res;
            }
        }
        return res;
    }
};