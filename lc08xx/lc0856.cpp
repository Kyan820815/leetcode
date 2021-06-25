//--- Q: 856. Score of Parentheses

//--- method 1: O(1) space, better
class Solution {
public:
    int scoreOfParentheses(string S) {
    	int l = 0, res = 0;
    	for (int i = 0; i < S.size(); ++i)    	
    	{
    		if (S[i] == '(') l++;
    		else l--;
    		if (S[i] == ')' && S[i-1] == '(')
    			res += 1 << l;
    	}
    	return res;
    }
};

//--- method 2: stack operation, O(n) space
class Solution {
public:
    int scoreOfParentheses(string S) {
    	stack<string> sk;
    	int res;
    	for (int i = 0; i < S.size(); ++i)
    	{
    		if (S[i] == '(')
    			sk.push("(");
    		else
    		{
    			if (sk.top() == "(")
    			{
    				sk.pop();
    				sk.push("1");
    			}
    			else
    			{
    				res = 0;
    				while (sk.top() != "(")
    				{
    					res += stoi(sk.top());
    					sk.pop();
    				}
    				sk.pop();
    				sk.push(to_string(res*2));
    			}
    		}
    	}
    	res = 0;
    	while (sk.size())
    	{
    		res += stoi(sk.top());
    		sk.pop();
    	}
    	return res;
    }
};