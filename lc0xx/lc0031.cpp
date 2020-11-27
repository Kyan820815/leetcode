//--- Q: 031. Next Permutation

//--- method 1:
// find first lower number than last (from right to left), 
// then find the first number larger than it (left to right) and swap
// sort idx_lower+1, end
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int small = nums.size()-1, big;
        for (int i = nums.size()-1; i > 0; i--)
        {
        	if (nums[i] > nums[i-1])
        	{
        		small = i-1;
        		break;
        	}
        }
        if (small == nums.size()-1)
        {
        	reverse(nums.begin(), nums.end());
        	return;
        }
        else
        {
        	for (big = small+1; big < nums.size(); big++)
        	{
        		if (nums[small] >= nums[big])
        			break;
        	}
        	swap(nums[small], nums[big-1]);
        	sort(nums.begin()+small+1, nums.end());
        }
    }
};