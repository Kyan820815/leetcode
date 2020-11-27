//--- Q: 268. Missing Number

//--- method 1: sum method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	sum += i;
        	res += nums[i];
        }
        return sum+nums.size()-res;
    }
};

//--- method 2: bit operation method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            res ^= (i+1);
            res ^= nums[i];
        }
        return res;
    }
};

//--- method 3: binary search
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int left = 0, right = nums.size();
    	while (left < right)
    	{
    		int mid = (left+right)/2;
    		if (nums[mid] > mid)
    			right = mid;
    		else left = mid+1;
    	}
    	return right;
    }
};