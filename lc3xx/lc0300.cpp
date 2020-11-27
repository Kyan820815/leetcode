//--- Q: 300. Longest Increasing Subsequence

//--- method 1: O(nlogn), similar with method 2, but different search method
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	vector<int> seq;
    	int left, right;
    	if (!nums.size()) return 0;
    	seq.push_back(nums[0]);
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		left = 0, right = seq.size()-1;
    		while(left < right)
    		{
    			int mid = (left+right) / 2;
    			if (seq[mid] < nums[i])
    				left = mid+1;
    			else
    				right = mid;
    		}
			if (left == seq.size()-1 && nums[i] > seq[left])
    			seq.push_back(nums[i]);
			else
				seq[left] = nums[i];
    	}
    	return seq.size();
    }
};

//--- method 2: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	vector<int> seq;
    	int sign;
    	if (!nums.size()) return 0;
    	seq.push_back(nums[0]);
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		sign = 1;
    		for (int j = 0; j < seq.size(); ++j)
    		{
    			if (nums[i] <= seq[j])
    			{
    				seq[j] = nums[i];
    				sign = 0;
    				break;
    			}
    		}
    		if (sign) seq.push_back(nums[i]);
    	}
    	return seq.size();
    }
};

//--- method 3: dp, O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	vector<int> seq(nums.size(),1);
        if (!nums.size()) return 0;
    	int max_len = 1;
    	for (int i = 1; i < nums.size(); ++i)
    	{
            int max_len_per = 1;
    		for (int j = 0; j < i; ++j)
    		{
    			if (nums[i] > nums[j])
                {
                    if (max_len_per < seq[j]+1)
                        max_len_per = seq[j]+1;
                }
    		}
            seq[i] = max_len_per;
            if (max_len < max_len_per)
                max_len = max_len_per;
    	}
    	return max_len;
    }
};