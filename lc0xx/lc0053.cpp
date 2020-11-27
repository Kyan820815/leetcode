//--- Q: 053. Maximum Subarray

//--- method 1: simplified dp, better memory allocation
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max, sum;
        max = sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            sum = (sum > 0) ? sum+nums[i] : nums[i];
        	if (sum > max)
        		max = sum;
        }
        return max;
    }
};

//--- method 2: dp with space O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max;
        int dp[nums.size()];    //--- maximun subarray ending with index i;

        max = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = nums[i] + ((dp[i-1] > 0) ? dp[i-1] : 0);
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};


//--- method 3: divide and conquer (subtle method)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide(nums, 0, nums.size()-1);
    }

    int divide(vector<int>& nums, int start, int end)
    {
        int mid, max_left, max_right, max_cross;

        if (start < end)
        {
            mid = (start + end)/2;
            max_left = divide(nums, start, mid);
            max_right = divide(nums, mid+1, end);
            max_cross = find_cross_arr(nums, start, mid, end);

            return max(max(max_left, max_right),max_cross);
        }
        else return nums[start];
    }

    int find_cross_arr(vector<int>& nums, int start, int mid, int end)
    {
        int max_left = INT_MIN, max_right = INT_MIN;
        int sum;

        sum = 0;
        for (int i = mid; i >= start; --i)
        {
            sum += nums[i];
            max_left = max(max_left, sum);
        }

        sum = 0;
        for (int i = mid+1; i <= end; ++i)
        {
            sum += nums[i];
            max_right = max(max_right, sum);
        }

        return max_left + max_right;
    }
};