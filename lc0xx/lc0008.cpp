//--- Q: 008. String to Integer (atoi)

//--- method 1: elegant solution, better
class Solution {
public:
    int myAtoi(string str) {
        int i, sum = 0, sign = 1;

        for (i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
                continue;
            else break;
        }

        if (str[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }

        while(str[i] >= '0' && str[i] <= '9')
        {
            if (sum > INT_MAX/10 || (sum == INT_MAX/10 && str[i]-'0' > 7)) return INT_MAX;
            if (sum < INT_MIN/10 || (sum == INT_MIN/10 && (str[i]-'0')*sign < -8)) return INT_MIN;
            sum = sum*10 + sign*(str[i++]-'0');
        }
        return sum;
    }
};

//--- method 2: digit by digit to find number string
class Solution {
public:
    int myAtoi(string str) {
    	string number;
    	int start, end, first = 0, sum = 0, neg = 1, sign = 0;
    	
    	for (int i = 0; i < str.size(); ++i)
    	{
    		if ('0' <= str[i] && str[i] <= '9')
    		{
                first = 1;
    			if (sum > INT_MAX/10 || sum == INT_MAX/10 && (str[i]-'0')*neg > 7) return INT_MAX;
                if (sum < INT_MIN/10 || sum == INT_MIN/10 && (str[i]-'0')*neg < -8) return INT_MIN;
                sum = sum*10 + (str[i]-'0')*neg;
    		}
    		else
    		{
    			if (first)
    				break;
    			else if (sign)
    				return 0;
    			else if (str[i] == '-')
	    		{
	    			sign = 1;
	    			neg = -1;			
	    		}
	    		else if (str[i] == '+')
	    			sign = 1;
	    		else if (str[i] != ' ')
	    			return 0;
    		}
    	}
    	return sum;
    }
};