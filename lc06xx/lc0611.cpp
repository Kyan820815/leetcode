//--- Q: 611. Valid Triangle Number 

//--- method 1: O(n^2logn)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    	int n = nums.size();
    	int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; ++i)
        {
        	for (int j = i+1; j < n-1; ++j)
        	{
        		int left = j+1, right = n-1;
        		int sum = nums[i]+nums[j];
        		while (left < right)
        		{
        			int mid = (left+right) / 2;
        			if (nums[mid] < sum)
        				left = mid+1;
        			else
        				right = mid;
        		}
                if (sum < nums[left])
                    res += (left-j);
                else
                    res += (left-1-j);
        	}
        }
        return res;
    }
};

//--- method 2: O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    	int n = nums.size();
    	int res = 0;
        sort(nums.begin(), nums.end());
    	for (int i = n-1; i >= 1; --i)
    	{
    		int left = 0, right = i-1;
    		while (left < right)
    		{
    			if (nums[left]+nums[right] > nums[i])
    			{
    				res += right-left;
    				--right;
    			}
    			else ++left;
    		}
    	}
        return res;
    }
};
