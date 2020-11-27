//--- Q: 55. Jump Game

//--- method 1: greedy method
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int reach = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (i > reach || reach >= nums.size()-1)
    			break;
    		reach = max(reach, i + nums[i]);
    	}
    	return reach >=  nums.size()-1;
    }
};