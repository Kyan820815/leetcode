//--- Q: 150. Evaluate Reverse Polish Notation

//--- method 1-1: clean code
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> sk;
    	int first, second;
    	for (int i = 0; i < tokens.size(); ++i)
    	{
    		if (tokens[i] != "+" && tokens[i] != "-" &&
    		 	tokens[i] != "*" && tokens[i] != "/")
    			sk.push(stoi(tokens[i]));
    		else
    		{
    			second = sk.top();
    			sk.pop();
    			first = sk.top();
    			sk.pop();
    			if (tokens[i] == "+")
    				sk.push(first+second);
    			else if (tokens[i] == "-")
    				sk.push(first-second);
    			else if (tokens[i] == "*")
    				sk.push(first*second);
    			else if (tokens[i] == "/")
    				sk.push(first/second);
    		}
    	}
    	return sk.top();
    }
};

//--- method 1: stack operation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	stack<int> sk;
    	int first, second, sum, sign;
    	for (int i = 0; i < tokens.size(); ++i)
    	{
    		if (tokens[i] != "+" && tokens[i] != "-" &&
    		 	tokens[i] != "*" && tokens[i] != "/")
    		{
                sign = 1;
                sum = 0;
                if (tokens[i][0] == '-')
                    sign = -1;
                else
                    sum = tokens[i][0]-'0';
                for (int j = 1; j < tokens[i].size(); ++j)
    				sum = sum*10 + tokens[i][j]-'0';
    			sk.push(sum*sign);
    		}
    		else
    		{
    			second = sk.top();
    			sk.pop();
    			first = sk.top();
    			sk.pop();
    			if (tokens[i] == "+")
    				sk.push(first+second);
    			else if (tokens[i] == "-")
    				sk.push(first-second);
    			else if (tokens[i] == "*")
    				sk.push(first*second);
    			else if (tokens[i] == "/")
    				sk.push(first/second);
    		}
    	}
    	return sk.top();
    }
};