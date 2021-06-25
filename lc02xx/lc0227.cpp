//--- Q: 227. Basic Calculator II

//--- method 1: one pass check, space: O(1)
class Solution {
public:
    int calculate(string s) {
    	int sum, now, i = 0;
    	char op;
    	int ans = 0, sign = 1;
    	while (i < s.size())
    	{
    		if (s[i] == ' ' || s[i] == '+')
    		{
    			++i;
    			continue;
    		}
    		else if (s[i] == '-')
    		{
    			++i;
    			sign = -1;
    			continue;
    		}
    		sum = 0;
			while (s[i] >= '0' && s[i] <= '9')
				sum = sum*10 + (s[i++]-'0');
			while (s[i] == ' ')
				++i;
			now = sum;
			while (s[i] == '*' || s[i] == '/')
			{
				op = s[i++];
				while (s[i] == ' ')
					++i;
				sum = 0;
    			while (s[i] >= '0' && s[i] <= '9')
					sum = sum*10 + (s[i++]-'0');
				while (s[i] == ' ')
					++i;
				if (op == '*')
					now *= sum;
				else
					now /= sum;
			}
			ans += now*sign;
			sign = 1;
    	} 
    	return ans;
    }
};

//--- method 2: two pass check with stack, space: O(n)
class Solution {
public:
    int calculate(string s) {
    	stack<int> sk;
    	char op = '+';
    	int sum = 0;

    	for (int i = 0; i < s.size(); ++i)
    	{
    		if (s[i] <= '9' && s[i] >= '0')
    			sum = sum*10 + (s[i]-'0');
    		if (i == s.size()-1 || (s[i] < '0' && s[i] !=' '))
    		{
    			if (op == '+')
    				sk.push(sum);
    			else if (op == '-')
    				sk.push(-sum);
    			else if (op == '*' || op == '/')
    			{
    				int tmp = (op == '*') ? sk.top()*sum : sk.top()/sum;
		    		sk.pop();
		    		sk.push(tmp);
    			}
	    		sum = 0;
    			op = s[i];
    		}
    	}
    	sum = 0;
    	while(sk.size() != 0)
    	{
    		sum += sk.top();
    		sk.pop();
    	}
    	return sum;
    }
};