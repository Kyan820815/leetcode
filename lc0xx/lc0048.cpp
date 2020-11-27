//--- Q: 048. Rotate Image

//--- method 1: vertical rotation then diagonal rotatiion
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    	for (int i = 0; i < matrix.size()/2; ++i)
    	{
    		vector<int> temp = matrix[i];
    		matrix[i] = matrix[matrix.size()-1-i];
    		matrix[matrix.size()-1-i] = temp;
    	}

        int col = matrix[0].size();
        int start = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
        	for (int j = start; j < matrix[0].size(); ++j)
        	{
        		if (i != j)
        			swap(matrix[i][j], matrix[j][i]);
        	}
        	start++;
        	col--;
        }
    }
};