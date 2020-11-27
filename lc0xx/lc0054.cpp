//--- Q: 054. Spiral Matrix

//--- method 1: boundary condition, better
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

//--- method 2: fill min_val with boundary condition
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