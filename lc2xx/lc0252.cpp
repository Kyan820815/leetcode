//--- Q: 252. Meeting Rooms

//--- method 1: find overlapping time
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (!intervals.size()) return true;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[0] < b[0];
             });
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < end) return false;
            else
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return true;
    }
};