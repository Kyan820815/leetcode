//--- Q: 202. Happy Number

//--- method 1: happy number will not be 4
class Solution {
public:
    bool isHappy(int n) {
    	while (n != 4 && n != 1)
    	{
    		int tmp = n, sum = 0;
    		while (tmp)
    		{
    			sum += pow(tmp%10, 2);
    			tmp /= 10;
    		}
    		n = sum;
    	}
    	return (n == 4) ? false : true;
    }
};

//--- method 2: happy number will not be 4
class Solution {
public:
    bool isHappy(int n) {
    	int slow = n, fast = n;
    	while (true)
    	{
    		slow = findnext(slow);
    		fast = findnext(fast);
    		fast = findnext(fast);
    		if (slow == fast) break;
    	}
    	return slow == 1;
    }
    int findnext(int n)
    {
    	int sum = 0;
    	while (n)
    	{
    		sum += pow(n%10, 2);
    		n /= 10;
    	}
    	return sum;
    }
};