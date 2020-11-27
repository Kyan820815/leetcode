//--- Q: 59. Spiral Matrix II

//--- method 1: array operation
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	int r = 0, c = -1, now = 0;
    	int hor = n, ver = n-1, shift;
        vector<vector<int>> res(n, vector<int>(n));
        while (1)
        {
        	shift = hor;
        	while (shift > 0)
        	{
        		res[r][++c] = ++now;
        		--shift;
        	}
        	--hor;
        	if (!hor && !ver) break;
        	
        	shift = ver;
        	while (shift > 0)
        	{
        		res[++r][c] = ++now;
        		--shift;
        	}
        	--ver;
        	if (!hor && !ver) break;
        	
        	shift = hor;
        	while (shift > 0)
        	{
        		res[r][--c] = ++now;
        		--shift;
        	}
        	--hor;
        	if (!hor && !ver) break;
        	
        	shift = ver;
        	while (shift > 0)
        	{
        		res[--r][c] = ++now;
        		--shift;
        	}
        	if (!hor && !ver) break;
        	--ver;
        }
        return res;
    }
};