//--- Q: 452. Minimum Number of Arrows to Burst Balloons

//--- method 1: sort the second term
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (!points.size()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int res = 1, min_end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > min_end) {
                ++res;
                min_end = points[i][1];
            }
        }
        return res;
    }
};