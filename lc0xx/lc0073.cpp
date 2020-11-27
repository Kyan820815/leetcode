//--- Q: 73. Set Matrix Zeroes

//--- method 1: matrix operation
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int row = matrix.size(), col = matrix[0].size();
    	bool row_zero = false, col_zero = false;
    	for (int i = 0; i < row; ++i)
    	{
    		if (matrix[i][0] == 0)
    		{
    			col_zero = true;
    			break;
    		}
    	}
    	for (int i = 0; i < col; ++i)
    	{
    		if (matrix[0][i] == 0)
    		{
    			row_zero = true;
    			break;
    		}
    	}
    	for (int i = 1; i < row; ++i)
    	{
    		for (int j = 1; j < col; ++j)
    		{
    			if (!matrix[i][j])
    				matrix[i][0] = matrix[0][j] = 0;
    		}
    	}   
    	for (int i = 1; i < row; ++i)
    	{
    		for (int j = 1; j < col; ++j)
    		{
    			if (!matrix[i][0] || !matrix[0][j])
    				matrix[i][j] = 0;
    		}
    	}
    	if (row_zero)
    	{
    		for (int i = 0; i < col; ++i)
    			matrix[0][i] = 0;
    	}
    	if (col_zero)
    	{
    		for (int i = 0; i < row; ++i)
    			matrix[i][0] = 0;
    	}
    }
};