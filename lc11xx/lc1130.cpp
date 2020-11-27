//--- Q: 1130. Minimum Cost Tree From Leaf Values

//--- method 1: O(n^2)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        while (arr.size() > 1) {
            int minidx, minv = INT_MAX;
            for (int i = 0; i < arr.size()-1; ++i) {
                int now = arr[i] * arr[i+1];
                if (minv > now) {
                    minv = now;
                    minidx = i;
                }
            }
            arr[minidx] = max(arr[minidx], arr[minidx+1]);
            arr.erase(arr.begin()+minidx+1);
            res += minv;
        }
        return res;
    }
};

//--- method 2: O(n)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
    	vector<int> sk = {INT_MAX};

    	for (int i = 0; i < arr.size(); ++i)
    	{
    		while (sk.size() && sk.back() < arr[i])
    		{
    			int remove = sk.back();
    			sk.pop_back();
    			res += remove*min(sk.back(), arr[i]);
    		}
    		sk.push_back(arr[i]);
    	}
    	for (int i = 1; i < sk.size()-1; ++i)
    		res += sk[i]*sk[i+1];
    	return res;
    }
};