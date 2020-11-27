//--- Q: 001. Two Sum

//--- method 1: sort then find index from left and right, better
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int *index;
        vector<int> ans;

        index = (int *)malloc(nums.size()*sizeof(int));
        for(int i = 0; i < nums.size(); ++i)
        	index[i] = i;

        divide(nums, left, right, index);

        while(left != right)
        {
        	if (nums[left]+nums[right] < target)
        		left++;
        	else if (nums[left]+nums[right] > target)
        		right--;
        	else
        		break;
        }
        ans.push_back(index[left]);
        ans.push_back(index[right]);
        return ans;
    }

    void divide(vector<int>& nums, int start, int end, int *index) {
    	int mid;
    	if (start < end)
    	{
    		mid = (start+end)/2;
    		divide(nums, start, mid, index);
    		divide(nums, mid+1, end, index);
    		conquer(nums, start, mid, end, index);
    	}
    }
    void conquer(vector<int>& nums, int start, int mid, int end, int *index) {
    	int left = start, right = mid+1, idx = 0;
    	int test[end-start+1], index_test[end-start+1];
    	
    	while(left <= mid && right <= end)
    	{
    		if (nums[left] < nums[right])
    		{
    			test[idx] = nums[left];
    			index_test[idx++] = index[left++];	
    		}
    		else
    		{
    			test[idx] = nums[right];
    			index_test[idx++] = index[right++];
    		}
    	}
    	while(left <= mid)
    	{
    		test[idx] = nums[left];
    		index_test[idx++] = index[left++];
    	}
    	while(right <= end)
    	{
    		test[idx] = nums[right];
    		index_test[idx++] = index[right++];
    	}
    	for (int i = 0; i < idx; ++i)
    	{
    		nums[i+start] = test[i];
    		index[i+start] = index_test[i];
    	}
    }
};

//--- method 2: hash map one way (unordered map)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> sumMap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sumMap.count(nums[i]))
            {
                ans.push_back(sumMap[nums[i]]);
                ans.push_back(i);
            }
            else
                sumMap[target-nums[i]] = i;
        }
        return ans;
    }
};