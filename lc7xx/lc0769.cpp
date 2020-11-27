//--- Q: 769. Max Chunks To Make Sorted

//--- method 1: linear seach i & arr[idx]
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	int res = 1, maxv = arr[0];
    	for (int i = 1; i < arr.size(); ++i)
    	{
            if (arr[i] > maxv)
            {
                if (i > maxv || i == arr.size()-1)
                    ++res;
                maxv = arr[i];
            }
        }
    	return res;
    }
};