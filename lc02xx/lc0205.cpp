//--- Q: 205. Isomorphic Strings

//--- method 1: bidirectional operation
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> foward(128, -1), back(128, -1);
        for (int i = 0; i < s.size(); ++i)
        {
        	int s_int = (int)s[i];
        	int t_int = (int)t[i];
        	if (foward[s_int] == -1)
        	{
        		foward[s_int] = t_int;
        		if (back[t_int] != -1)
        			return false;
        		back[t_int] = s_int;
        	}
        	else
        	{
        		if (foward[s_int] != t_int || back[t_int] != s_int)
        			return false;
        	}
        }
        return true;
    }
};