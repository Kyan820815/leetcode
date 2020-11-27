//--- Q: 152. Maximum Product Subarray

//--- method 1: dp, O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int minus_max, plus_max;
    	int n_minus_max, n_plus_max;
    	int return_max;

    	if (nums.size() == 0) return 0;

    	return_max = minus_max = plus_max = nums[0];
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if (nums[i] == 0)
    		{
    			plus_max = 0;
    			minus_max = 0;
    		}
    		n_plus_max = max(nums[i], max(plus_max*nums[i], minus_max*nums[i]));
    		n_minus_max = min(nums[i], min(plus_max*nums[i], minus_max*nums[i]));
    		plus_max = n_plus_max;
    		minus_max = n_minus_max;
    		if (return_max < plus_max) return_max = plus_max;
    	}
    	return return_max;
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