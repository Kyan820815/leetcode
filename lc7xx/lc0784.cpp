//--- Q: 784. Letter Case Permutation

//--- method 1: dfs recursion
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res_vec;
        string res;
        dfs(S, 0, res_vec, res);
        return res_vec;
    }
    void dfs(string S, int start, vector<string> &res_vec, string &res)
    {
    	if (start == S.size())
    	{
    		res_vec.push_back(res);
    		return;
    	}
    	if (S[start] < '0' || S[start] > '9')
    	{

    		res.push_back(S[start]^32);
    		dfs(S, start+1, res_vec, res);
    		res.pop_back();
    		
    	}
		res.push_back(S[start]);
		dfs(S, start+1, res_vec, res);
		res.pop_back();
    }
};

//--- methid 2: iteration
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res = {""};
        for (int i = 0; i < S.size(); ++i)
        {
        	char c = S[i];
        	int size = res.size();
        	if (c >= '0' && c <= '9')
        	{
        		for (int j = 0; j < size; ++j)
        			res[j].push_back(c);
        	}
        	else
        	{
        		for (int j = 0; j < size; ++j)
	        	{
	        		res.push_back(res[j]);
					res[j].push_back(c);
					res[j+size].push_back(c^32);	        		
	        	}
        	}
        }
        return res;
    }
};