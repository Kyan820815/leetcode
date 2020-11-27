//--- Q: 1186. Maximum Subarray Sum with One Deletion

//--- method 1: two subarray
class Solution {
public:
    int maximumSum(vector<int>& arr) {
    	int maxv = INT_MIN, sum1 = 0, sum2 = 0, del1 = 0, del2 = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
        	if (sum1 <= 0)
        		sum1 = del1 = 0;
        	if (sum2-del2 <= 0)
        		sum2 = del2 = 0;
        	sum1 += arr[i];
        	sum2 += arr[i];
        	maxv = max(maxv, max(sum1-del1, sum2-del2));
        	del1 = min(del1, arr[i]);
        	del2 = min(del2, arr[i]);
        }
        return maxv;
    }
};