//--- Q: 1266. Minimum Time Visiting All Points

//--- method 1: O(n), one pass, better
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < points.size(); ++i) {
            int diffx = abs(points[i][0] - points[i-1][0]);
            int diffy = abs(points[i][1] - points[i-1][1]);
            res += max(diffx, diffy);
        }
        return res;
    }
};

//--- method 2: O(n), one pass
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < points.size(); ++i) {
            int diffx = abs(points[i][0] - points[i-1][0]);
            int diffy = abs(points[i][1] - points[i-1][1]);
            res += abs(diffx-diffy) + min(diffx, diffy);
        }
        return res;
    }
};