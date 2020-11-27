//--- Q: 119. Pascal's Triangle II

//--- method 1-1: O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res(1,1);
    	for (int i = 0; i <= rowIndex; ++i)
    	{
    		int pre = 1, now;
    		for (int j = 1; j < i; ++j)
    		{
    			now = res[j];
                res[j] = res[j]+pre;
				pre = now;    			
    		}
    		if (i > 0) res.push_back(1);
    	}
    	return res;
    }
};

//--- method 1-2: O(2*n)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> last;
    	for (int i = 0; i <= rowIndex; ++i)
    	{
    		vector<int> res;
    		res.push_back(1);
    		for (int j = 1; j < i; ++j)
    			res.push_back(last[j]+last[j-1]);
    		if (i > 0) res.push_back(1);
    		last = res;
    	}
    	return last;
    }
};