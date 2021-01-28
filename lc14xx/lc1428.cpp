//--- Q: 1428. Leftmost Column with at Least a One

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

//--- method 1: O(rlog(c))
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int right = dim[1];
        for (int i = 0; i < dim[0]; ++i) {
            int left = 0;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (!binaryMatrix.get(i, mid)) {
                    left = mid+1;
                } else {
                    right = mid;
                }
            }
            if (!left) {
                return left;
            }
            right = left;
        }
        return right == dim[1] ? -1 : right;
    }
};

//--- method 2: O(r+c)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int row = dim[0], col = dim[1], r = 0, c = col-1, res = -1;
        while (r < row && c >= 0) {
            if (binaryMatrix.get(r, c)) {
                res = c--;
            } else {
                ++r;
            }
        }
        return res;
    }
};