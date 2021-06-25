//--- Q: 056. Merge Intervals

//--- method 1: O(nlogn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
  		vector<vector<int>> out_vec;

  		sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});

  		if (!intervals.size()) return out_vec;

  		out_vec.push_back(intervals[0]);
  		for (int i = 1; i < intervals.size(); ++i)
  		{
  			if (intervals[i].front() <= out_vec.back().back())
  				out_vec.back().back() = max(intervals[i].back(), out_vec.back().back());
  			else
  				out_vec.push_back(intervals[i]);
  		}
  		return out_vec;     
    }
};