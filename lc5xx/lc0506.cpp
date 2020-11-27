//--- Q: 506. Relative Ranks

//--- mehtod 1: sort then find index
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
    	vector<int> order;
    	vector<string> res(nums.size(), "");
    	for (int i = 0; i < nums.size(); ++i)
    		order.push_back(i);
    	sort(order.begin(), order.end(), [&nums](int &a, int &b)
		{
			return nums[a] > nums[b];
		});
    	for (int i = 0; i < res.size(); ++i)
    	{
    		res[order[i]] = to_string(i+1);
    		if (i == 0)
    			res[order[i]] = "Gold Medal";
    		else if (i == 1)
    			res[order[i]] = "Silver Medal";
    		else if (i == 2)
    			res[order[i]] = "Bronze Medal";
    	}
    	return res;
    }
};