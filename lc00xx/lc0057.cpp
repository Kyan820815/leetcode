//--- Q: 0057. Insert Interval

//--- method 1: O(n) pass
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (!intervals.size()) {
            return vector<vector<int>>{newInterval};
        }
        vector<vector<int>> res;
        int i = 0, used = 0, cnt = 0;
        while (cnt++ < intervals.size()+1) {
            vector<int> interval;
            if (!used && (i == intervals.size() || newInterval[0] < intervals[i][0])) {
                interval = newInterval;
                used = 1;
            } else {
                interval = intervals[i++];
            }
            if (!res.size() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};