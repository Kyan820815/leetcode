//--- Q: 0759. Employee Free Time

//--- method 1: merge based on start time, not created merge array
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        auto sorted_itv = divide(0, schedule.size()-1, schedule);
        int maxend = sorted_itv[0].end;
        for (int i = 1; i < sorted_itv.size(); ++i) {
            if (sorted_itv[i].start > maxend) {
                res.push_back(Interval(maxend, sorted_itv[i].start));
                maxend = sorted_itv[i].end;
            } else {
                maxend = max(maxend, sorted_itv[i].end);
            }
        }
        return res;
    }
    vector<Interval> divide(int start, int end, vector<vector<Interval>> schedule) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, schedule);
            auto right = divide(mid+1, end, schedule);
            return merge(left, right);
        } else {
            return schedule[start];
        }
    }
    vector<Interval> merge(vector<Interval> &left, vector<Interval> &right) {
        vector<Interval> res;
        for (int i = 0, j = 0; i < left.size() || j < right.size();) {
            if (j == right.size() || i < left.size() && left[i].start < right[j].start) {
                res.push_back(left[i++]);
            } else {
                res.push_back(right[j++]);
            }
        }
        return res;
    }
};

//--- method 2: construct merge array
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        auto sorted_itv = divide(0, schedule.size()-1, schedule);
        int maxend = sorted_itv[0].end;
        for (int i = 1; i < sorted_itv.size(); ++i) {
            res.push_back(Interval(sorted_itv[i-1].end, sorted_itv[i].start));
        }
        return res;
    }
    vector<Interval> divide(int start, int end, vector<vector<Interval>> schedule) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, schedule);
            auto right = divide(mid+1, end, schedule);
            return merge(left, right);
        } else {
            return schedule[start];
        }
    }
    vector<Interval> merge(vector<Interval> &left, vector<Interval> &right) {
        vector<Interval> res;
        for (int i = 0, j = 0; i < left.size() || j < right.size();) {
            auto push = (j == right.size() || i < left.size() && left[i].start < right[j].start) ? left[i++] : right[j++];
            if (!res.size() || res.back().end < push.start)  {
                res.push_back(push);
            } else {
                res.back().end = max(res.back().end, push.end);
            }
        }
        return res;
    }
};