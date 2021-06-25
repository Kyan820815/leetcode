//--- Q: 697. Degree of an Array

//--- method 1: two times pass
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        int size = -1, minl = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        	map[nums[i]].push_back(i);
        for (auto &m: map)
        {
        	if ((int)m.second.size() > size)
        	{
        		size = m.second.size();
        		minl = m.second.back()-m.second.front()+1;
        	}
        	else if (m.second.size() == size)
        		minl = min(minl, m.second.back()-m.second.front()+1);
        }
        return minl;
    }
};

//--- method 2: one times pass
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> map, start;
        int minl = INT_MAX, degree = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (!start.count(nums[i]))
        		start[nums[i]] = i;
        	++map[nums[i]];
        	if (map[nums[i]] > degree)
        	{
        		degree = map[nums[i]];
        		minl = i-start[nums[i]]+1;
        	}
        	else if (map[nums[i]] == degree)
        		minl = min(minl, i-start[nums[i]]+1);
        }
        return minl;
    }
};