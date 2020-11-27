//--- Q: 565. Array Nesting

//--- method 1: one pass O(n), space O(1)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		int max_len = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			int len = 0;
			while (nums[i] != i)
			{
				swap(nums[i], nums[nums[i]]);
				++len;
			}
			if (len > max_len)
				max_len = len;
		}
		return max_len;
    }
};

//--- method 2: one pass O(n), space O(n)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		vector<int> used(nums.size(),1);
		int max_len = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (!used[i]) continue;
			int len = 0, idx = i;
			while (nums[idx] != i)
			{
				used[idx] = 0;
				idx = nums[idx];
				++len;
			}
			++len;
			if (len > max_len)
				max_len = len;
		}
		return max_len;
    }
};