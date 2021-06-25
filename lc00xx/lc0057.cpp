//--- Q: 57. Insert Interval

//--- method 1: O(n) pass
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    	vector<vector<int>> res;
    	bool check = false;
        int i = 0, cnt = 0;
        if (!intervals.size()) return {newInterval};
        while (cnt < intervals.size()+1)
        {
            if (!check && (i == intervals.size() || newInterval[0] < intervals[i][0]))
     		{
     			if (!res.size() || newInterval[0] > res.back()[1])
     				res.push_back(newInterval);
     			else
     				res.back()[1] = max(res.back()[1], newInterval[1]);
     			check = true;
     		}
     		else
     		{
     			if (!res.size() || intervals[i][0] > res.back()[1])
     				res.push_back(intervals[i]);
     			else
     				res.back()[1] = max(res.back()[1], intervals[i][1]);
                ++i;
     		}
            ++cnt;
        }
     	return res;
    }
};