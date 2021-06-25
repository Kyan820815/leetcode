//--- Q: 912. Sort an Array

//--- method 1: merge sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size()-1);
        return nums;
    }
    void divide(vector<int> &nums, int start, int end)
    {
    	int mid;
    	if (start < end)
    	{
    		mid = (start + end)/2;
    		divide(nums, start, mid);
    		divide(nums, mid+1, end);
    		conquer(nums, start, mid, end);
    	}
    }
    void conquer(vector<int> &nums, int start, int mid, int end)
    {
    	int left=start, right=mid+1, idx=0;
    	int copy[end-start+1];

    	while(left <= mid && right<= end)
    		copy[idx++] = (nums[left]<=nums[right]) ? nums[left++] : nums[right++];
    	while(left <= mid)
    		copy[idx++] = nums[left++];
    	while(right <= end)
    		copy[idx++] = nums[right++];
    	for (int i = 0; i < idx; ++i)
    		nums[start+i] = copy[i];
    }
};

//--- method 2: quick sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    	quicksort(nums, 0, nums.size()-1);
        return nums;
    }
    void quicksort(vector<int> &nums, int start, int end)
    {
    	int mid;
    	if (start < end)
    	{
    		mid = partition(nums, start, end);
    		quicksort(nums, start, mid-1);
    		quicksort(nums, mid+1, end);
    	}
    }
    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = start + random()%(end-start+1);
        swap(nums[pivot], nums[end]);
        int idx = start-1;
        for (int i = start; i < end; ++i) {
            if (nums[i] < nums[end]) {
                swap(nums[++idx], nums[i]);
            }
        }
        swap(nums[++idx], nums[end]);
        return idx;
    }
};

//--- method 3: selection sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    	selection(nums);
        return nums;
    }
    void selection(vector<int> &nums)
    {
    	int minIdx;
    	for (int i = 0; i < nums.size()-1; ++i)
    	{
    		minIdx = i;
    		for (int j = i+1; j < nums.size(); j++)
    			if (nums[j] < nums[minIdx]) minIdx = j;
    		swap(nums[i], nums[minIdx]);
    	}
    }
};

//--- method 4: insertion sort (1)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    	insertion(nums);
        return nums;
    }
    void insertion(vector<int> &nums)
    {
    	int ch, j;
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		ch = nums[i];
    		for (j = i; j > 0; --j)
    		{
    			if (ch < nums[j-1]) nums[j] = nums[j-1];
    			else break;
     		}
     		nums[j] = ch;
    	}
    }
};

//--- method 4: insertion sort (2)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        insertion(nums);
        return nums;
    }
    void insertion(vector<int> &nums)
    {
        int ch, j;
        for (int i = 1; i < nums.size(); ++i)
        {
            ch = nums[i];
            for (j = i-1; j >= 0; --j)
            {
                if (ch < nums[j]) nums[j+1] = nums[j];
                else break;
            }
            nums[j+1] = ch;
        }
    }
};

//--- method 5: bubble sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    	bubble(nums);
        return nums;
    }
    void bubble(vector<int> &nums)
    {
    	bool  sort;
    	for (int i = 0; i < nums.size()-1; ++i)
    	{
    		sort = true;
    		for (int j = 0; j < nums.size()-i-1; ++j)
    		{
    			if (nums[j] > nums[j+1])
    			{
    				swap(nums[j], nums[j+1]);
    				sort = false;
    			}
    		}
    		if (sort) break;
    	}
    }
};