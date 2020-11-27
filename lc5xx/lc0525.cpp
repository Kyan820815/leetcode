//--- Q: 525. Contiguous Array

//--- method 1: accumulative sum. O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	int sum = 0, max = 0;
    	unordered_map<int,int> map;
    	map[0] = -1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[i] == 0)
    			sum--;
    		else
    			sum++;
			if (!map.count(sum))
				map[sum] = i;
			else
			{
				if (i-map[sum] > max)
					max = i-map[sum];
			}
    	}
    	return max;
    }
};

//--- method 1-2: vector instead of map, better
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	int sum = nums.size(), max = 0;
    	vector<int> map(nums.size()*2+1,-2);
    	map[sum] = -1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[i] == 0)
    			sum--;
    		else
    			sum++;
			if (map[sum] == -2)
				map[sum] = i;
			else
			{
				if (i-map[sum] > max)
					max = i-map[sum];
			}
    	}
    	return max;
    }
};