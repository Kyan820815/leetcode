//--- Q: 179. Largest Number

//--- method 1: divide and conquer
class Solution {
public:
    string largestNumber(vector<int>& nums) {
		vector<string> nums_str(nums.size());
		string out;
		for (int i = 0; i < nums.size(); ++i)
			nums_str[i] = to_string(nums[i]);    	    
		divide(nums_str, 0, nums_str.size()-1);

		for (int i = 0; i < nums_str.size(); ++i)
			out = out + nums_str[i];    	    
    	return (out[0] == "0") ? "0" : out;
    }
    void divide(vector<string> &nums, int start, int end)
    {
    	int mid;
    	if (start < end)
    	{
    		mid = (start+end) / 2;
    		divide(nums, start, mid);
    		divide(nums, mid+1, end);
    		conquer(nums, start, mid, end);
    	}
    }
    void conquer(vector<string> &nums, int start, int mid, int end)
    {
    	int left = start, right = mid+1, index = 0;
    	int l_id, r_id;
    	int sign;
    	vector<string> copy(end-start+1);
    	while(left <= mid && right <= end)
    	{
    		if (nums[left]+nums[right] < nums[right]+nums[left])
    			copy[index++] = nums[right++];
    		else
    			copy[index++] = nums[left++];
    	}
    	while(left <= mid) copy[index++] = nums[left++];
    	while(right <= end) copy[index++] = nums[right++];
    	for (int i = 0; i < index; ++i)
    		nums[start+i] = copy[i];
    }
};