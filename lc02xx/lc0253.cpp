//--- Q: 0253. Meeting Rooms II

//--- method 1: map count
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> time;
        for (auto &interval: intervals) {
            ++time[interval[0]];
            --time[interval[1]];
        }
        int room = 0, res = 0;
        for (auto &t: time) {
            room += t.second;
            res = max(res, room);
        }
        return res;
    }
};

//--- method 2: sort start time and end time
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for (auto &interval: intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int room = 0;
        for (int i = 0, j = 0; i < start.size(); ++i) {
            if (start[i] < end[j]) {
                ++room;
            } else {
                ++j;
            }
        }
        return room;
    }
};