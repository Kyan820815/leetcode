//--- Q: 240. Search a 2D Matrix II

//--- method 1: linear search, O(n), better
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

//--- method 2: binary search, O(nlogn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int left, right, row_limit;
    
        left = 0, right = row-1;        
        while(left < right)
        {
            int mid = (left+right) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                left = mid+1;
            else
                right = mid;
        }
        if (matrix[left][0] == target) return true;
        
        row_limit = (!left) ? 0 : left--;
        for (int i = 0; i <= row_limit; ++i)
        {
            left = 0, right = col-1;
            while(left < right)
            {
                int mid = (left+right) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] < target)
                    left = mid+1;
                else
                    right = mid;
            }
            if (matrix[i][left] == target) return true;
        }
        return false;
    }
};