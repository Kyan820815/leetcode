//--- Q: 007. Reverse Integer

//--- method 1: index by index checking, better
class Solution {
public:
    int reverse(int x) {
        int sum = 0, rem;
        while(x != 0)
        {
            rem = x % 10;
            x = x / 10;

            if (sum > INT_MAX/10 || sum == INT_MAX/10 && rem > 7) return 0;
            if (sum < INT_MIN/10 || sum == INT_MIN/10 && rem < -8) return 0;
            sum = sum*10+rem;
        }
        return sum;        
    }
};

//--- method 2: first remove 0 then, compare size first then value
class Solution {
public:
    int reverse(int x) {
        string min_str = to_string(INT_MIN);
        string max_str = to_string(INT_MAX);
        string comp_str;    
        string x_str = to_string(x);
      	int ex_size, overflow = 0, sum=0;

      	if (x == 0)
      		return 0;

        for (int i = x_str.size()-1; i >= 0; --i)
        {
        	if (x_str[i] != '0')
        	{
        		x_str = x_str.substr(0,i+1);
        		break;
        	}
        }

        if (x < 0)
        {
        	x_str = x_str.substr(1,x_str.size()-1);
        	min_str = min_str.substr(1,min_str.size()-1);
        	ex_size = min_str.size();
        }
        else
        	ex_size = max_str.size();

        if (x_str.size() < ex_size)
        	overflow = 0;
        else if (x_str.size() == ex_size)
        {
        	comp_str = (x > 0) ? max_str : min_str;
        	for (int i = 0; i < x_str.size(); ++i)
        	{
        		if (x_str[x_str.size()-1-i] > comp_str[i])
        		{
        			overflow = 1;
        			break;
        		}
        		else if (x_str[x_str.size()-1-i] < comp_str[i])
        		{
        			overflow = 0;
        			break;
        		}
        	}
        }
        else
        	overflow = 1;

        if (overflow)
        	return 0;
        else
        {
        	for (int i = 0; i < x_str.size(); i++)
        		sum = sum + pow(10,i)*((int)x_str[i]-48);
        	if (x < 0)
        		return (-1)*sum;
        	else
        		return sum;
        }
    }
};