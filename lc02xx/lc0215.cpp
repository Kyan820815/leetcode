//--- Q: 215. Kth Largest Element in an Array

//--- method 1: O(n), quick select
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int find;
  	    quicksort(nums, 0, nums.size()-1, k-1, find);
        return find;
    }
    int random(int a, int b)
    {
    	return rand()%(b-a+1) + a;
    }
    int partition(vector<int> &nums, int start, int end)
    {
    	int idx = start-1;
    	swap(nums[random(start, end)], nums[end]);
    	for (int i = start; i < end; ++i)
    		if (nums[i] > nums[end])
    			swap(nums[++idx], nums[i]);
    	swap(nums[++idx], nums[end]);
    	return idx;
    }
    void quicksort(vector<int> &nums, int start, int end, int k, int &find)
    {
    	if (start < end)
    	{
    		int mid = partition(nums, start, end);
    		if (mid == k)
                find = nums[mid];
    		else if (mid > k)
                quicksort(nums, start, mid-1, k, find);
    		else
    			quicksort(nums, mid+1, end, k, find);
    	}
        else find = nums[start];
	}
};

//--- method 2: max heap, o(klogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        nums.insert(nums.begin(),0);
        
        buildMaxHeap(nums, len);
        for(int i = 1; i <= k; ++i)
        {
            swap(nums[1], nums[len--]);
            max_heapify(nums, 1, len);   
        }
        return nums[len+1];
    }
    void buildMaxHeap(vector<int> &nums, int len)
    {
        for (int i = len/2; i >= 1; --i)
            max_heapify(nums, i, len);
    }
    void max_heapify(vector<int> &nums, int root, int length)
    {
        int left_idx = root*2, right_idx = root*2+1;
        int largest_idx;
        if (left_idx <= length && nums[left_idx] > nums[root])
            largest_idx = left_idx;
        else largest_idx = root;

        if (right_idx <= length && nums[right_idx] > nums[largest_idx])
            largest_idx = right_idx;
        if (largest_idx != root)                 
        {
            swap(nums[largest_idx], nums[root]);
            max_heapify(nums, largest_idx, length);
        }
    }
};

//--- method 3: sort then find, O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
  		sort(nums.begin(), nums.end(), [](const int a, const int b){return a > b;});
  		return nums[k-1];
    }
};

//--- method 4: priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (heap.size() < k)
                heap.push(nums[i]);
            else
            {
                if (nums[i] > heap.top())
                {
                    heap.pop();
                    heap.push(nums[i]);
                }
            }
        }
        return heap.top();
    }       
};