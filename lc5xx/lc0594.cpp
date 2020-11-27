//--- Q: 594. Longest Harmonious Subsequence

//--- method 1: map
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = INT_MIN;
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i)
        	++map[nums[i]];
        for (auto &m: map)
        {
            if (map.count(m.first+1))
                res = max(res, m.second+map[m.first+1]);
        }
        return (res==INT_MIN) ? 0 : res;
    }
};

//--- method 2: sort
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = INT_MIN, start = 0, new_start = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i]-nums[start] > 1)
        		start = new_start;
            if (nums[i]-nums[start] == 1)
        		res = max(res, i-start+1);
            if (nums[i] != nums[i-1])
        	    new_start = i;
        }
        return (res==INT_MIN) ? 0 : res;
    }
};