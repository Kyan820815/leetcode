//--- Q. 017. Letter Combinations of a Phone Number

//--- method 1: DFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	string nStr = "";
    	vector<string> out;

    	if (digits.size() == 0) return out;
    	dfs(digits, 0, nStr, out);
    	return out;
    }

    void dfs(string digits, int nIdx, string nStr, vector<string> &out)
	{
		char c;
		if (nIdx < digits.size())
		{
			for (int i = 0; i < 4; ++i)
			{
				if (i == 3 && digits[nIdx] != '7' && digits[nIdx] != '9') break;
				c = 'a' + (digits[nIdx]-'2')*3 + i;
				c = (digits[nIdx] > '7') ? c+1 : c;
				
				nStr.push_back(c);
				dfs(digits, nIdx+1, nStr, out);
				nStr.pop_back();
			}
		}
		else out.push_back(nStr);
	}
};