//--- Q: 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

//--- method 1: prefix sum
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size(), col = mat[0].size(), max = 0;
        int leftsum, topsum, lastsum;
        vector<vector<int>> psum(row+1, vector<int>(col+1, 0));
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + mat[i-1][j-1];
                if (i-max >= 1 && j-max >= 1) {
                    int sum = psum[i][j] - psum[i-max-1][j] - psum[i][j-max-1] + psum[i-max-1][j-max-1];
                    if (sum <= threshold) {
                        ++max;
                    }
                }
            }
        }
        return max;
    }
};

//--- method 2: prefix sum + binary search
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> psum(row, vector<int>(col, 0));
        psum[0][0] = mat[0][0];
        for (int i = 1; i < row; ++i) {
            psum[i][0] = psum[i-1][0] + mat[i][0];
        }
        for (int j = 1; j < col; ++j) {
            psum[0][j] = psum[0][j-1] + mat[0][j];
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + mat[i][j];
            }
        }
        int left = 1, right = min(row, col);
        while (left <= right) {
            int mid = (right-left)/2 + left;
            if (check(mid-1, threshold, psum)) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return left-1;
    }
    bool check(int side, int threshold, vector<vector<int>>& psum) {
        int row = psum.size(), col = psum[0].size();
        for (int i = side; i < row; ++i) {
            for (int j = side; j < col; ++j) {
                int leftsum = 0, topsum = 0, lastsum = 0;
                if (i-side-1 >= 0 && j-side-1 >= 0) {
                    lastsum = psum[i-side-1][j-side-1];
                    leftsum = psum[i][j-side-1];
                    topsum = psum[i-side-1][j];
                } else if (i-side-1 >= 0) {
                    topsum = psum[i-side-1][j];
                } else if (j-side-1 >= 0) {
                    leftsum = psum[i][j-side-1];
                }
                if (psum[i][j] - leftsum - topsum + lastsum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
};