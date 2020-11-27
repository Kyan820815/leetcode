//--- Q: 38. Count and Say

//--- method 1: process last res
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        for (int i = 2; i <= n; ++i)
        {
        	string tmp = "";
        	int cnt = 1;
            for (int i = 0; i <= res.size(); ++i)
            {
            	if (i > 0 && res[i] == res[i-1]) ++cnt;
            	else if (i == res.size() || (i > 0 && res[i] != res[i-1]))
            	{
                    tmp += (cnt + '0');
                    tmp += res[i-1];
            		cnt = 1;
            	}
            }
            res = tmp;
        }
        return res;
    }
};