//--- Q: 1272. Remove Interval

//--- method 1: find disjoint section
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] >= toBeRemoved[1] || intervals[i][1] <= toBeRemoved[0]) {
                res.push_back({intervals[i][0], intervals[i][1]});
            } else {
                if (intervals[i][0] < toBeRemoved[0])
                    res.push_back({intervals[i][0], toBeRemoved[0]});
                if (intervals[i][1] > toBeRemoved[1])
                    res.push_back({toBeRemoved[1], intervals[i][1]});
            }
        }
        return res;
    }
};
