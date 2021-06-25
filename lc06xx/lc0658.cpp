//--- Q: 658. Find K Closest Elements

//--- method 1: binary search then left and right search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    	int n = arr.size();
    	int left = 0, right = n-1, idx;
    	while (left < right)
    	{
    		int mid = (left+right) / 2;
    		if (arr[mid] < x)
    			left = mid+1;
    		else
    			right = mid;
    	}
    	if (left != 0)
        	idx = abs(arr[left]-x) < abs(arr[left-1]-x) ? left : left-1;
        else
            idx = left;

        left = right = idx;
        --k;
        while (k > 0)
        {
        	int left_val = INT_MAX, right_val = INT_MAX;
        	if (left > 0)
        		left_val = abs(arr[left-1]-x);
        	if (right < n-1)
        		right_val = abs(arr[right+1]-x);

        	if (left_val <= right_val)
        		--left;
        	else
        		++right;
        	--k;
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);
    }
};

//--- method 2: binary search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-k;
        while (left < right) {
            int mid = (left+right)>>1;
            if (x-arr[mid] > arr[mid+k]-x)
                left = mid+1;
            else
                right = mid;
        }
        return vector<int>(arr.begin()+left, arr.begin()+k+left);
    }
};