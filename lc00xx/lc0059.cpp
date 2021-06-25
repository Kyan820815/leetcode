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

//--- method 2: clean code
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int r = 0, c = 0, id = 0, cnt = 1, total = n*n;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (total--) {
            res[r][c] = cnt++;
            int nr = r + dir[id][0];
            int nc = c + dir[id][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || res[nr][nc] != 0) {
                id = (id+1)%4;
                r += dir[id][0];
                c += dir[id][1];
            } else {
                r = nr, c = nc;
            }
        }
        return res;
    }
};
