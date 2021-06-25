//--- Q: 1198. Find Smallest Common Element in All Rows

//--- method 1-1: binary search
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        for (int j = 0; j < col; ++j) {
            int target = mat[0][j], find = 1;
            for (int i = 1; i < row && find; ++i) {
                int left = 0, right = col-1;
                int pos = bsearch(left, right, target, mat[i]);
                if (mat[i][pos] != target) {
                    find = 0;
                }
            }
            if (find) {
                return target;
            }
        }
        return -1;
    }
    int bsearch(int left, int right, int target, vector<int> &mat) {
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mat[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

//--- method 1-2: optimized binary search
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<int> last_start(row, 0);
        for (int j = 0; j < col; ++j) {
            int target = mat[0][j], find = 1;
            for (int i = 1; i < row && find; ++i) {
                int left = last_start[i], right = col-1;
                int pos = bsearch(left, right, target, mat[i]);
                if (mat[i][pos] != target) {
                    find = 0;
                }
                last_start[i] = pos;
            }
            if (find) {
                return target;
            }
        }
        return -1;
    }
    int bsearch(int left, int right, int target, vector<int> &mat) {
        while (left < right) {
            int mid = left + (right-left)/2;
            if (mat[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

//--- method 2: count first number having n times
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> map;
        for (auto &row: mat) {
            for (auto &element: row) {
                if (++map[element] == mat.size()) {
                    return element;
                }
            }
        }
        return -1;
    }
};
