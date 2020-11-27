//--- Q: 754. Reach a Number

//--- method 1: determine the diff odd or even
class Solution {
public:
    int reachNumber(int target) {
    	int sum = 0, now = 1, cnt = 0;
        target = abs(target);
    	while (sum < target)
    	{
    		sum += now;
    		++now;
    		++cnt;
    	}
    	if (sum == target) return cnt;
    	else if ((sum-target) % 2 == 0)
    		return cnt;
    	else
    		return (now % 2) ? cnt+1 : cnt+2;
    }
};