//--- Q: 172. Factorial Trailing Zeroes

//--- method 1: count # 5
class Solution {
public:
    int trailingZeroes(int n) {
    	int res = 0;
    	while (n)
    	{
    		res += n/5;
    		n /= 5;
    	}
    	return res;
    }
};