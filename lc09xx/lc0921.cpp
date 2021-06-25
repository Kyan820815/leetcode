//--- Q: Minimum Add to Make Parentheses Valid

//--- method 1: stack operation
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> sk;
        int res = 0;
        for (int i = 0; i < S.size(); ++i)
        {
        	if (S[i] == '(')
        		sk.push(S[i]);
        	else
        	{
        		if (sk.size() == 0)
        			++res;
        		else
        			sk.pop();
        	}
        }
        res += sk.size();
        return res;
    }
};

//--- method 2: O(1) space
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, res = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == ')') {
                if (!left)
                    ++res;
                else
                    --left;
            } else {
                ++left;
            }
        }
        return left + res;
    }
};