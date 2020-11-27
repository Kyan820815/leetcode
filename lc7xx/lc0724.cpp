//--- Q: 724. Find Pivot Index

//--- method 1: comparison between left_sum and right_sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    	int sum = 0, left_sum, right_sum;
        if (!nums.size()) return -1;
    	for (int i = 0; i < nums.size(); ++i)
    		sum += nums[i];
    	left_sum = 0, right_sum = sum-nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (left_sum == right_sum)
        		return i;
            if (i+1 < nums.size())
            {
            	left_sum += nums[i];
            	right_sum -= nums[i+1];
            }
        }
        return -1;
    }
};

//--- method 2: clean code, like method 1
class Solution {
public:
	int pivotIndex(vector<int> &nums) {
		int sum = 0, cursum = 0;
		for (int i = 0; i < nums.size(); ++i)
			sum += nums[i];
		for (int i = 0; i < nums.size(); ++i)
		{
			if (sum-nums[i] == cursum * 2)
				return i;
			cursum += nums[i];
		}
        return -1;
	}
};
