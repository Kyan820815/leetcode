//--- Q: 394. Decode String

//--- method 1: dfs recursion
class Solution {
public:
    string decodeString(string s) {
    	string ans = "";
    	int jump;
        dfs(s, 0, ans, jump);
        return ans;
    }
    void dfs(string s, int start, string &ans, int &jump)
    {
    	string now_str = "";
    	int cnt;
    	for (int i = start; i < s.size(); ++i)
    	{
    		if (s[i] >= '0' && s[i] <= '9')
    		{
    			cnt = 0;
    			while (s[i] >= '0' && s[i] <= '9')
    			{
    				cnt = cnt*10 + s[i]-'0';
    				++i;
    			}
	    		//--- dfs
	    		dfs(s, i+1, ans, jump);

	    		string tmp = ans;
	    		for (int j = 0; j < cnt; ++j)
	    			now_str = now_str + tmp;
	    		i = i + jump;
    		}
    		else if (s[i] != '[' && s[i] != ']')
    		{
    			now_str.push_back(s[i]);
    		}
    		else if (s[i] == ']')
    		{
    			ans = now_str;
    			jump = i-start+1;
    			return;
    		}
    	}
    	ans = now_str;
    }
};

//--- method 2: iterative stack
class Solution {
public:
    string decodeString(string s) {
    	stack<string> str_sk;
    	stack<int> cnt_sk;
    	int cnt = 0;
    	string now_str = "";
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if (s[i] >= '0' && s[i] <= '9')
    			cnt = cnt*10 + s[i] - '0';
    		else if (s[i] == '[')
    		{
    			str_sk.push(now_str);
    			cnt_sk.push(cnt);
    			cnt = 0;
    			now_str.clear();
    		}
    		else if (s[i] == ']')
    		{
    			string tmp = str_sk.top();
    			for (int i = 0; i < cnt_sk.top(); ++i)
    			{
    				tmp += now_str;
    			}
    			cnt_sk.pop();
    			str_sk.pop();
    			now_str = tmp;
    		}
    		else
    			now_str += s[i];
    	}
    	return now_str;
    }
};