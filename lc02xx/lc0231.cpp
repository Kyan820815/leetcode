//--- Q: 231. Power of Two

//--- method 1: O(logn) time
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n%2 == 0)
        	n /= 2;
        return n == 1 ? true : false;
    }
};

//--- method 2: O(logn) time with bit operation
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	int cnt = 0;
    	while (n)
    	{
    		cnt += (1 & n);
    		if (cnt > 1) break;
    		n >>= 1;
    	}
    	return cnt == 1 ? true : false;
    }
};

//--- method 3: O(1) time
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	return n > 0 && !(n&(n-1)) ? true : false;
    }
};