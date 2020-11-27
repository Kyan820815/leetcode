//--- Q: 074. Search a 2D Matrix

//--- method 1: binary search, O(logn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row*col-1;

        while(left < right)
        {
        	int mid = (left+right) / 2;
            int r = mid/col, c = mid%col;
        	if (matrix[r][c] == target)
        		return true;
        	else if (matrix[r][c] > target)
        		right = mid;
        	else
        		left = mid+1;
        }
        if (matrix[left/col][left%col] == target)
            return true;
        else
            return false;
    }
};

//--- method 2: linear search, O(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        int r = 0, c = col-1;
        while (r < row && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                r++;
            else 
                c--;
        }
        return false;
    }
};