//--- Q: 1047. Remove All Adjacent Duplicates In String

//--- method 1: stack, better
class Solution {
public:
    string removeDuplicates(string S) {
    	int idx = 0;
    	string res = "";
    	while (idx < S.size())
    	{
    		while (res.size() && res.back() == S[idx])
    		{
    			res.pop_back();
    			++idx;
    		}
        	res.push_back(S[idx++]);
        }
    	return res;
    }
};

//--- method 2: erase, slow
class Solution {
public:
    string removeDuplicates(string S) {
    	int idx = 0;
    	while (idx < S.size())
    	{
    		int left = idx, right = idx;
    		if (right < S.size() && S[idx] == S[idx+1])
    		{
    			++right;
    			S = S.erase(left, 2);
    			idx = 0;
    		}
    		else ++idx;
    	}
    	return S;
    }
};