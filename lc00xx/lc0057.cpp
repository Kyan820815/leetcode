//--- Q: 0057. Insert Interval
//--- last written: 2023/07/02

//--- method 1: O(n) pass
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), i = 0, used = 0;
        while (i < n || !used) {
            vector<int> cur;
            if (!used && (i == n || newInterval[0] < intervals[i][0])) {
                cur = newInterval;
                used = 1;
            } else {
                cur = intervals[i];
                ++i;
            }
            if (!res.size() || res.back()[1] < cur[0]) {
                res.push_back(cur);
            } else {
                res.back()[1] = max(res.back()[1], cur[1]);
            }
        }
        return res;
    }
};
