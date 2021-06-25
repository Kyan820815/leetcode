//--- Q: 69. Sqrt(x)

//--- method 1: binary search
class Solution {
public:
    int mySqrt(int x) {
		int left = 0, right = x;
        if (x == 1 || x == 0) return x;
		while (left < right)
		{
			int mid = (left+right) / 2;
			if (mid <= x/mid) left = mid+1;
			else right = mid;
		}
		return left-1;    	
    }
};