//--- Q: 263. Ugly Number

//--- method 1-1: clean code 
class Solution {
public:
    bool isUgly(int num) {
    	if (num == 0) return false;
		while(num % 2 == 0)
			num /= 2;    	
		while(num % 3 == 0)
			num /= 3;    	
		while(num % 5 == 0)
			num /= 5;    	
        return num == 1;
    }
};

//--- method 1-2: /2 or /3 or /5 
class Solution {
public:
    bool isUgly(int num) {
    	int end;
    	if (num == 1) return true;
        else if (num == 0) return false;
        while (num != 1)
        {
        	end = 0;
        	if (num % 2 == 0)
        	{
        		end = 1;
        		num /= 2;
        	}
        	if (num % 3 == 0)
        	{
        		end = 1;
        		num /= 3;
        	}
        	if (num % 5 == 0)
        	{
        		end = 1;
        		num /= 5;
        	}
        	if (end == 0)
        		return false;
        }
        return true;
    }
};