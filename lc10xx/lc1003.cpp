//--- Q: 1003. Check If Word Is Valid After Substitutions

//--- method 1: stack operation
class Solution {
public:
    bool isValid(string S) {
		vector<int> sk;
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == 'c')
		 	{
		 		int n = sk.size();
		 		if (n < 2 || sk[n-1] != 'b' || sk[n-2] != 'a')
		 			return false;
		 		sk.pop_back();
		 		sk.pop_back();
		 	}
		 	else sk.push_back(S[i]);
		}
		return sk.size() == 0;     
    }
};