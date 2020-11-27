//--- Q: 209. Minimum Size Subarray Sum

//--- method 1: O(n), one pass
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
     	int left, right;
     	int sum = 0, min_len = INT_MAX;
     	left = right = 0;

     	while(right < nums.size())
     	{
     		sum += nums[right];
 			while(sum >= s)
 			{
 				min_len = min(min_len, right-left+1);
 				sum -= nums[left++];
 			}
     		right++;
     	}
    	return (min_len == INT_MAX) ? 0 : min_len;
    }
};

//--- method 2: O(nlogn), binrary search
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int min_len = INT_MAX;
    	vector<int> sum(nums.size()+1, 0);
    	
    	for (int i = 1; i < sum.size(); ++i)
    		sum[i] = sum[i-1] + nums[i-1];
    	for (int i =  1; i < sum.size(); ++i)
    	{
    		int right = binarySearch(i, sum.size()-1, sum, s, sum[i-1]);
    		if (right == sum.size()-1 && sum[right]-sum[i-1] < s) continue;
    		min_len = min(right-i+1, min_len);
    	}
    	return (min_len == INT_MAX) ? 0 : min_len;
    }
    int binarySearch(int left, int right, vector<int> &sum, int target, int trivial)
    {
    	while(left < right)
    	{
    		int mid = (left+right)/2;
    		if (sum[mid]-trivial < target)
    			left = mid+1;
    		else
    			right = mid; 
    	}
    	return left;
    }
};

//--- method 2: my version
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n+1, 0);
        int min = INT_MAX, minus;
        for (int i = 1; i <= n; ++i)
            sums[i] = sums[i-1] + nums[i-1];
        for (int i = 1; i <= n; ++i)
        {
            int left = i, right = n;
            minus = sums[i-1];
            while(left < right)
            {
                int mid = (left+right)/2;
                if (sums[mid]-minus < s)
                    left = mid+1;
                else
                    right = mid;
            }
            if (sums[left]-minus >= s)
            {
                if (left-i+1 < min)
                    min = left-i+1;
            }
        }
        return min == INT_MAX ? 0 : min;
    }
};