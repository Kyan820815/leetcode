//--- Q: Contains Duplicate

//--- method 1: hash map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};

//--- method 2: sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if (nums[i] == nums[i-1])
    			return true;
    	}
    	return false;
    }
};