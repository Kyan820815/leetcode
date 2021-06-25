//--- Q: 768. Max Chunks To Make Sorted II

//--- method 1: O(n) space
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	int res = 1, maxv = INT_MIN, minv = INT_MAX;
    	vector<int> left_max(arr.size()), right_min(arr.size());
    	for (int i = 0; i < arr.size(); ++i)
    	{
    		maxv = max(maxv, arr[i]);
            left_max[i] = maxv;
    		minv = min(minv, arr[arr.size()-i-1]);
            right_min[arr.size()-i-1] = minv;
    	}
    	for (int i = 0; i < arr.size()-1; ++i)
    	{
    		if (left_max[i] <= right_min[i+1])
    			++res;
    	}
    	return res;
    }
};

//--- method 2: stack
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	stack<int> sk;
    	for (int i = 0; i < arr.size(); ++i)
    	{
    		if (sk.size() && arr[sk.top()] > arr[i])
    		{
    			int maxv = sk.top();
    			sk.pop();
    			while (sk.size() && arr[sk.top()] > arr[i])
    				sk.pop();
    			sk.push(maxv);
    		}
    		else sk.push(i);
    	}
    	return sk.size();
    }
};