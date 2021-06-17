//--- Q: 759. Employee Free Time

//--- method 1: construct merge array
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        auto arr = divide(0, schedule.size()-1, schedule);
        vector<Interval> res;
        for (int i = 1; i < arr.size(); ++i) {
            res.push_back({arr[i-1].end, arr[i].start});
        }
        return res;
    }
    vector<Interval> divide(int start, int end, vector<vector<Interval>> &schedule) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, schedule);
            auto right = divide(mid+1, end, schedule);
            return merge(left, right);
        }
        return schedule[start];
    }
    vector<Interval> merge(vector<Interval> &left, vector<Interval> &right) {
        int i = 0, j = 0, start, end;
        if (left[i].start < right[j].start) {
            start = left[i].start, end = left[i++].end;
        } else {
            start = right[j].start, end = right[j++].end;
        }
        vector<Interval> res;
        while (i < left.size() && j < right.size()) {
            if (left[i].start < right[j].start) {
                if (end < left[i].start) {
                    res.push_back({start, end});
                    start = left[i].start, end = left[i++].end;
                } else {
                    end = max(end, left[i++].end);
                }
            } else {
                if (end < right[j].start) {
                    res.push_back({start, end});
                    start = right[j].start, end = right[j++].end;
                } else {
                    end = max(end, right[j++].end);
                }
            }
        }
        while (i < left.size()) {
            if (end < left[i].start) {
                res.push_back({start, end});
                start = left[i].start, end = left[i++].end;
            } else {
                end = max(end, left[i++].end);
            }
        }
        while (j < right.size()) {
            if (end < right[j].start) {
                res.push_back({start, end});
                start = right[j].start, end = right[j++].end;
            } else {
                end = max(end, right[j++].end);
            }
        }
        res.push_back({start, end});
        return res;
    }
};

//--- method 2: merge based on start time, not created merge array
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        auto arr = divide(0, schedule.size()-1, schedule);
        vector<Interval> res;
        int end = arr[0].end;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i].start > end) {
                res.push_back({end, arr[i].start});
                end = arr[i].end;
            } else {
                end = max(end, arr[i].end);
            }
        }
        return res;
    }
    vector<Interval> divide(int start, int end, vector<vector<Interval>> &schedule) {
        if (start < end) {
            int mid = start + (end-start)/2;
            auto left = divide(start, mid, schedule);
            auto right = divide(mid+1, end, schedule);
            return merge(left, right);
        }
        return schedule[start];
    }
    vector<Interval> merge(vector<Interval> &left, vector<Interval> &right) {
        int i = 0, j = 0;
        vector<Interval> res;
        
        while (i < left.size() && j < right.size()) {
            if (left[i].start < right[j].start) {
                res.push_back(left[i++]);
            } else {
                res.push_back(right[j++]);
            }
        }
        while (i < left.size()) {
            res.push_back(left[i++]);
        }
        while (j < right.size()) {
            res.push_back(right[j++]);
        }
        return res;
    }
};