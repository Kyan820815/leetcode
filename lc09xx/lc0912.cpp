//--- Q: 0912. Sort an Array

//--- method 1: quick sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        divide(0, nums.size()-1, nums);
        return nums;
    }
    void divide(int start, int end, vector<int> &nums) {
        if (start < end) {
            int mid = partition(start, end, nums);
            divide(start, mid-1, nums);
            divide(mid+1, end, nums);
        }
    }
    int partition(int start, int end, vector<int> &nums) {
        int pivot = random()%(end-start+1) + start, idx = start-1;
        swap(nums[pivot], nums[end]);
        for (int i = start; i < end; ++i) {
            if (nums[i] < nums[end]) {
                swap(nums[++idx], nums[i]);
            }
        }
        swap(nums[++idx], nums[end]);
        return idx;
    }
};

//--- method 2: merge sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        divide(0, nums.size()-1, nums);
        return nums;
    }
    void divide(int start, int end, vector<int> &nums) {
        if (start < end) {
            int mid = start + (end-start)/2;
            divide(start, mid, nums);
            divide(mid+1, end, nums);
            merge(start, mid, end, nums);
        }
    }
    void merge(int start, int mid, int end, vector<int> &nums) {
        int i = start, j = mid+1;
        vector<int> cpy;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                cpy.push_back(nums[i++]);
            } else {
                cpy.push_back(nums[j++]);
            }
        }
        while (i <= mid) {
            cpy.push_back(nums[i++]);
        }
        while (j <= end) {
            cpy.push_back(nums[j++]);
        }
        for (int i = start; i <= end; ++i) {
            nums[i] = cpy[i-start];
        }
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

//--- method 4: insertion sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int val = nums[i], j;
            for (j = i-1; j >= 0; --j) {
                if (val < nums[j]) {
                    nums[j+1] = nums[j];
                } else {
                    break;
                }
            }
            nums[j+1] = val;
        }
        return nums;
    }
};

//--- method 5: bubble sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n; i >= 1; --i) {
            bool is_swap = false;
            for (int j = 0; j < i-1; ++j) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    is_swap = true;
                }
            }
            if (!is_swap) {
                break;
            }
        }
        return nums;
    }
};