//--- Q: 253. Meeting Rooms II

//--- method 1: sort start time and end time
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for (int i = 0; i < intervals.size(); ++i)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int res = 0, idx = 0;
        for (int i = 0; i < start.size(); ++i)
        {
            if (start[i] < end[idx]) ++res;
            else ++idx;
        }
        return res;
    }
};