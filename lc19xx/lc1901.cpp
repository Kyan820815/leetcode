//--- Q: 1901. Find a Peak Element II

//--- method 1: binary search, find col max
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), last = 0;
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int maxrow = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[maxrow][mid] < mat[i][mid]) {
                    maxrow = i;
                }
            }
            bool isLeft = mid-1 >= 0 && mat[maxrow][mid-1] > mat[maxrow][mid];
            bool isRight = mid+1 < n && mat[maxrow][mid+1] > mat[maxrow][mid];
            if (!isLeft && !isRight) {
                return vector<int>{maxrow, mid};
            } else if (isRight) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return vector<int>{-1,-1};
    }
};