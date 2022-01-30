//--- Q: 1198. Find Smallest Common Element in All Rows

//--- method 1: binary search
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), start = 0, k, find = 0;
        for (k = 0; k < col && !find; ++k) {
            find = 1;
            for (int i = 1; i < row; ++i) {
                int left = 0, right = col-1;
                while (left < right) {
                    int mid = left + (right-left)/2;
                    if (mat[i][mid] < mat[0][k]) {
                        left = mid+1;
                    } else {
                        right = mid;
                    }
                }
                if (mat[i][left] != mat[0][k]) {
                    find = 0;
                    break;
                }
            }
        }
        return find ? mat[0][k-1] : -1;
    }
};

//--- method 2: improved binary search
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size(), start = 0, k, find = 0;
        vector<int> last(row, 0);
        for (k = 0; k < col && !find; ++k) {
            find = 1;
            for (int i = 1; i < row; ++i) {
                int left = last[i], right = col-1;
                while (left < right) {
                    int mid = left + (right-left)/2;
                    if (mat[i][mid] < mat[0][k]) {
                        left = mid+1;
                    } else {
                        right = mid;
                    }
                }
                last[i] = left;
                if (mat[i][left] != mat[0][k]) {
                    find = 0;
                    break;
                }
            }
        }
        return find ? mat[0][k-1] : -1;
    }
};

//--- method 3: count first number having n times
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        unordered_map<int,int> map;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (++map[mat[i][j]] == row) {
                    return mat[i][j];
                }
            }
        }
        return -1;
    }
};