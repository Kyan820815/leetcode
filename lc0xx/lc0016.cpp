//--- Q: 016. 3Sum Closest

//--- method 1: sort and O(n) find
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX, ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; ++i)
        {
        	int pivot = nums[i];
        	int target1 = target-pivot;
        	int left = i+1, right = n-1;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
        	while(left < right)
        	{
        		int sum = nums[left]+nums[right];
        		if (abs(target-sum-pivot) < abs(diff))
	       			diff = target-sum-pivot;
        		if (sum < target1) left++;
        		else if (sum > target1) right--;
        		else break;
        	}
        }
        return target-diff;
    }
};