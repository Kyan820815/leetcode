//--- Q: 498. Diagonal Traverse

//--- method 1: find law of the problem
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    	if (matrix.size() == 0) return vector<int>{};
    	int row = matrix.size(), col = matrix[0].size();
    	int nums = row * col;
    	int r = 0, c = 0;
    	int left_down = -1;
    	vector<int> dig;
    	while(nums != 0)
    	{
			dig.push_back(matrix[r][c]);
			if (left_down == 1)
			{
				if (r+1 < row && c-1 >= 0)
				{
					r++; c--;
				}
				else if (r+1 < row)
				{
					r++;
					left_down = -1;
				}
				else
				{
					c++;
					left_down = -1;
				}
			}
			else
			{
				if (r-1 >= 0 && c+1 < col)
				{
					r--; c++;
				}
				else if (c+1 < col)
				{
					c++;
					left_down = 1;
				}
				else
				{
					r++;
					left_down = 1;
				}
			}
			nums--;
    	}
    	return dig;
    }
};