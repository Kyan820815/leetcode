//--- Q: 643. Maximum Average Subarray I

//--- method 1: linear processing
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    	int maxv = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (i < k)
        		sum += nums[i];
        	else
        	{
        		maxv = max(maxv, sum);
        		sum += nums[i];
        		sum -= nums[i-k];
        	}
        }
        maxv = max(maxv, sum);
        return (double)maxv/k;
    }
};