//--- Q: 054. Spiral Matrix

//--- method 1: clean code use dir
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int row = matrix.size(), col = matrix[0].size();
        int total = row*col, id = 0, r = 0, c = 0;
        vector<int> res;
        while (total--) {
            res.push_back(matrix[r][c]);
            matrix[r][c] = 101;
            int nr = r + dir[id][0];
            int nc = c + dir[id][1];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[nr][nc] == 101) {
                id = (id+1) % 4;
                r += dir[id][0];
                c += dir[id][1];
            } else {
                r = nr, c = nc;
            }
        }
        return res;
    }
};

//--- method 2: boundary condition, better
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	if (matrix.empty()) return {};

        vector<int> out;
        int w = matrix[0].size(), h = matrix.size();
        int hor=-1, ver=0;

        h--;
        while(1)
        {
        	if (w == 0) break;
        	for (int i = w; i > 0; --i) 
        		out.push_back(matrix[ver][++hor]);
        	w--;        	

        	if (h == 0) break;
        	for (int i = h; i > 0; --i) 
        		out.push_back(matrix[++ver][hor]);
        	h--;

        	if (w == 0) break;
        	for (int i = w; i > 0; --i)
        		out.push_back(matrix[ver][--hor]);
        	w--;

        	if (h == 0) break;
        	for (int i = h; i > 0; --i)
        		out.push_back(matrix[--ver][hor]);
        	h--;
        }
        return out;
    }
};

//--- method 2-2: iter
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = -1, cnt, total = row*col, idx = 0;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> shift = {col, row-1};
        vector<int> res;
        while (1) {
            for (int i = 0; i < 4; ++i) {
                int cnt = shift[idx]--;
                while (cnt--) {
                    r += dir[i][0];
                    c += dir[i][1];
                    res.push_back(matrix[r][c]);
                    --total;
                }
                idx ^= 1;
                if (!total) {
                    break;
                }
            }
            if (!total) {
                break;
            }
        }
        return res;
    }
};

//--- method 3: fill min_val with boundary condition
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
    	if (matrix.empty()) return out;
        int w=matrix[0].size(), h=matrix.size();
        int size = w*h;
        int hor=0, ver=0;
        while(size > 0)
        {
        	while(hor < w && matrix[ver][hor] != INT_MIN && size > 0) //--- right
        	{
        		out.push_back(matrix[ver][hor]);
        		matrix[ver][hor] = INT_MIN; 
        		hor++;
        		size--;
        	}
        	ver++;
        	hor--;
        	while(ver < h && matrix[ver][hor] != INT_MIN && size > 0) //--- down
        	{
        		out.push_back(matrix[ver][hor]);
        		matrix[ver][hor] = INT_MIN;
        		ver++;
        		size--;
        	}
        	hor--;
        	ver--;
        	while(hor >= 0 && matrix[ver][hor] != INT_MIN && size > 0) //--- left
        	{
        		out.push_back(matrix[ver][hor]);
        		matrix[ver][hor] = INT_MIN;
        		hor--;
        		size--;
        	}
        	ver--;
        	hor++;
        	while(ver >= 0 && matrix[ver][hor] != INT_MIN && size > 0) //--- top
        	{
        		out.push_back(matrix[ver][hor]);
        		matrix[ver][hor] = INT_MIN;
        		ver--;
        		size--;
        	}
        	hor++;
        	ver++;
        }
        return out;
    }
};