//--- Q: 022. Generate Parentheses

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	string str;
    	vector<string> out;

        dfs(n, 0, 0, out, str);
        return out;
    }
    void dfs(int n, int left, int right, vector<string> &out, string &str)
    {
    	if (left == right && left == n)
    	{
    		out.push_back(str);
    		return;
    	}
    	if (left < n)
    	{
    		str += "(";
    		dfs(n, left+1, right, out, str);
    		str.pop_back();
    	}
    	if (left > right)
    	{
    		str += ")";
    		dfs(n, left, right+1, out, str);
            str.pop_back();
    	}
    }
};