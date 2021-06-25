//--- Q: 890. Find and Replace Pattern

//--- method 1: bijection vector
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (int i = 0; i < words.size(); ++i)
        {
        	string str = words[i];
	        vector<int> go(26, -1);
	        vector<int> inv(26, -1);
        	bool right = true;
        	for (int j = 0; j < str.size(); ++j)
        	{
        		if (go[str[j]-'a'] == -1)
        		{
        			go[str[j]-'a'] = pattern[j]-'a';
        			if (inv[pattern[j]-'a'] == -1)
        				inv[pattern[j]-'a'] = str[j]-'a';
        			else if (inv[pattern[j]-'a'] != str[j]-'a')
        			{
        				right = false;
        				break;
        			}
        		}
        		else if (inv[pattern[j]-'a'] != str[j]-'a')
        		{
        			right = false;
        			break;
        		}
        	}
        	if (right)
        		res.push_back(str);
        }
        return res;
    }
};