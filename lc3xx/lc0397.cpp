//--- Q: 397. Integer Replacement

//--- method 1: recursive solution
class Solution {
public:
    int integerReplacement(int n) {
    	if (n == 1)
    		return 0;
        if (n&1 == 1)
        {
        	long long int t = n;
        	return min(integerReplacement((t+1)/2), integerReplacement((t-1)/2))+2;
        }
        else
        	return integerReplacement(n>>1)+1;
    }
};

//--- method 2: iterative solution
class Solution {
public:
    int integerReplacement(int n) {
    	int res = 0;
        long long int t = n;
    	while (t > 1)
    	{
    		if (t & 1)
    		{
    			if (t&2 && t != 3) ++t;
    			else --t;
    		}
    		else t >>= 1;
    		++res;
    	}
    	return res;
    }
};