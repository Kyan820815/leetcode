//--- Q: 0057. Insert Interval

//--- method 1: O(n) pass
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), used = 0;
        vector<vector<int>> res;
        for (int i = 0; i <= n || used;) {
            vector<int> cur_arr;
            if (!used) {
                if (i == n || newInterval[0] < intervals[i][0]) {
                    used = 1;
                    cur_arr = newInterval;
                } else {
                    cur_arr = intervals[i++];
                }
            } else if (i < n) {
                cur_arr = intervals[i++];
            }
            if (!cur_arr.size()) {
                break;
            }
            if (!res.size() || res.back()[1] < cur_arr[0]) {
                res.push_back(cur_arr);
            } else {
                res.back()[1] = max(res.back()[1], cur_arr[1]);
            }
        }
        return res;
    }
};