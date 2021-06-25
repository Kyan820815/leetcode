//--- Q: Complex Number Multiplication

//--- method 1: 
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
    	int first_left, first_right;
    	int second_left, second_right;
    	int left, right;
    	string res;
    	getNum(a, first_left, first_right);
    	getNum(b, second_left, second_right);
    	left = first_left * second_left - first_right * second_right;
    	right = first_left * second_right + first_right * second_left;
    	res = to_string(left) + "+" + to_string(right) + "i";
    	return res;
    }
    void getNum(string str, int &a, int &b)
    {
    	int i = 0, sign = 1;
    	a = b = 0;
    	if (str[i] == '-')
    	{
    		++i;
    		sign = -1;
    	}
    	while (str[i] != '+')
    		a = a*10 + (str[i++]-'0');
    	a *= sign;
    	sign = 1;
    	++i;
    	if (str[i] == '-')
    	{
    		++i;
    		sign = -1;
    	}
    	while (str[i] != 'i')
    		b = b*10 + (str[i++]-'0');
    	b *= sign;
    }
};