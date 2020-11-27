//--- Q: 229. Majority Element II

//--- method 1: O(n) one pass
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<vector<int>> maj(2, vector<int>(2,0));
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (maj[0][0] != 0 && maj[0][1] == nums[i])
            {
                maj[0][0]++;
            }
            else if (maj[1][0] != 0 && maj[1][1] == nums[i])
            {
                maj[1][0]++;
            }
            else if (maj[0][0] == 0)
            {
                maj[0][0]++;
                maj[0][1]=nums[i];
            }
            else if (maj[1][0] == 0)
            {
                maj[1][0]++;
                maj[1][1]=nums[i];
            }
            else
            {
                maj[0][0]--;
                maj[1][0]--;
            }
        }
    	for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] == maj[0][1])
        		cnt1++;
        	else if (nums[i] == maj[1][1])
        		cnt2++;
	    }	
        if (cnt1 > nums.size()/3)
            ans.push_back(maj[0][1]);
        if (cnt2 > nums.size()/3)
            ans.push_back(maj[1][1]);
        return ans;
    }
};