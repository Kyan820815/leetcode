//--- Q: 435. Non-overlapping Intervals

//--- method 1: one pass，remove start < end_until_now
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (!intervals.size()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> b) {
            return a[1] < b[1];
        });
        int end = intervals[0][1], res = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                ++res;
            } else {
                end = intervals[i][1];
            }
        }
        return res;
    }
};