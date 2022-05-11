//--- Q: 1288. Remove Covered Intervals

//--- method 1: sort
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), res = 1;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        });
        int right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][1] > right) {
                ++res;
                right = intervals[i][1];
            }
        }
        return res;
    }
};