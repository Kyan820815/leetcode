//--- Q: 018. 4Sum

//--- method 1: double for loop
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	int target1, left, right;
    	int n = nums.size();
    	vector<vector<int>> out;

    	if (n < 4) return out;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-3; ++i)
        {
        	if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
        	if (nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
        	if (i > 0 && nums[i] == nums[i-1]) continue;
        	for (int j = i+1; j < n-2; ++j)
        	{
        		if (j > i+1 && nums[j] == nums[j-1]) continue;
        		target1 = target - nums[i] - nums[j];
        		left = j+1;
        		right = n-1;

        		while(left < right)
        		{
        			if (nums[left] + nums[right] == target1)
        			{
        				out.push_back({nums[i], nums[j], nums[left++], nums[right--]});
        				while(left < right && nums[left-1] == nums[left]) left++;
        				while(left < right && nums[right+1] == nums[right]) right--;
        			}
        			else if (nums[left] + nums[right] < target1) left++;
        			else if (nums[left] + nums[right] > target1) right--;
        		}
        	}        	
        }
        return out;
    }
};

