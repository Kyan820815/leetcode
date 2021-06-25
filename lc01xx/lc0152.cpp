//--- Q: 152. Maximum Product Subarray

//--- method 1: dp, O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minv = 1, maxv = 1, res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int last_min = minv;
            int last_max = maxv;
            minv = min(nums[i], min(nums[i]*last_min, nums[i]*last_max));
            maxv = max(nums[i], max(nums[i]*last_min, nums[i]*last_max));
            res = max(res, maxv);
        }
        return res;
    }
};

//--- method 2: divide and conquer, O(nlogn)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	return divide(nums, 0, nums.size()-1);;
    }
    int divide(vector<int> &nums, int start, int end)
    {
    	int left_max, right_max, mid_max;
    	int mid;
    	if (start < end)
    	{
    		mid = (start+end)/2;
    		left_max = divide(nums, start, mid);
    		right_max = divide(nums, mid+1, end);
    		mid_max = conquer(nums, start, mid, end);
    		return max(left_max, max(right_max, mid_max));
    	}
    	else return nums[start];
    }
    int conquer(vector<int> &nums, int start, int mid , int end)
    {
    	int left_plus_max = 0, left_minus_max = 0;
    	int right_plus_max = 0, right_minus_max = 0;
    	int sum;

    	sum = 1;
    	for (int i = mid; i >= start; --i)
    	{
    		sum = sum * nums[i];
    		if (sum < left_minus_max) left_minus_max = sum;
    		if (sum > left_plus_max) left_plus_max = sum;
    	}

    	sum = 1;
    	for (int i = mid+1; i <= end; ++i)
    	{
    		sum = sum * nums[i];
    		if (sum < right_minus_max) right_minus_max = sum;
    		if (sum > right_plus_max) right_plus_max = sum;
    	}
    	return max(left_minus_max*right_minus_max, left_plus_max*right_plus_max);
    }
};