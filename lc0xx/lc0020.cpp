//--- Q: 020. Valid Parentheses

//--- method 1: stack
class Solution {
public:
    bool isValid(string s) {
  		string stack;
    	for (int i = 0; i < s.size(); ++i)
    	{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stack += s[i];
			else
			{
				if (stack.size() == 0)
					return false;
                
                switch (s[i])
                {
                    case ')':
                        if (stack[stack.size()-1] == '(')
                            stack.pop_back();
                        else
                            return false;
                            break;
                    case ']':
                         if (stack[stack.size()-1] == '[')
                            stack.pop_back();
                         else
                            return false;
                            break;
                    case '}':
                         if (stack[stack.size()-1] == '{')
                            stack.pop_back();
                         else
                            return false;
                            break;
                }
			}
    	}
    	return (stack.size() == 0) ? true : false;
    }
};