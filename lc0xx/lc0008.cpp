//--- Q: 008. String to Integer (atoi)

//--- method 1: elegant solution, better
class Solution {
public:
    int myAtoi(string s) {
        int num = 0, sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] == '+' || s[i] == '-') {
                sign = s[i] == '-' ? -1 : 1;
                ++i;
            }
            while (i < s.size() && isdigit(s[i])) {
                if (num > INT_MAX/10 || num == INT_MAX/10 && s[i] > '7') {
                    return INT_MAX;
                }
                if (num < INT_MIN/10 || num == INT_MIN/10 && s[i] > '8') {
                    return INT_MIN;
                }
                num = num*10 + sign*(s[i++]-'0');
            }
            break;
        }
        return num;
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