//--- Q: 402. Remove K Digits

//--- method 1: increasin stack
class Solution {
public:
    string removeKdigits(string num, int k) {
    	string res = "";
    	for (int i = 0; i < num.size(); ++i)
    	{
            while (res.size() && res.back() > num[i] && k)
            {
                res.pop_back();
                --k;
            }
            res.push_back(num[i]);
    	}
        for (int i = 0; i < k; ++i)
    		res.pop_back();
        int idx = 0;
        while (idx < res.size())
        {
            if (res[idx] != '0') break;
            ++idx;
        }
        res = res.substr(idx, res.size()-idx);
    	return !res.size() ? "0" : res;
    }
};