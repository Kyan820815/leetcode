//--- Q: 503. Next Greater Element II

//--- method 1: O(n) two pass
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size(), -1);
		stack<int> sk;
		for (int i = 0; i < nums.size(); ++i)
		{
			while (sk.size() != 0 && nums[sk.top()] < nums[i])
			{
				res[sk.top()] = nums[i];
				sk.pop();
			}
			sk.push(i);
		} 
		for (int i = 0; i < nums.size(); ++i)
		{
			while (sk.size() != 0 && nums[sk.top()] < nums[i])
			{
				res[sk.top()] = nums[i];
				sk.pop();
			}
		}         
		return res;
    }
};