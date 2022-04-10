//--- Q: 1886. Determine Whether Matrix Can Be Obtained By Rotation

//--- method 1: inplace swap
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<int> deg(4, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // deg 0
                deg[0] &= (mat[i][j] == target[i][j]);
                // deg 90 right
                deg[1] &= (mat[i][j] == target[j][n-i-1]);
                // deg 180 right
                deg[2] &= (mat[i][j] == target[n-i-1][n-j-1]);
                // deg 270 right
                deg[3] &= (mat[i][j] == target[n-j-1][i]);
            }
        }
        return deg[0] || deg[1] || deg[2] || deg[3];
    }
};

//--- method 2: roate
class Solution {
public:
    int n;
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        int cnt = 4;
        while (cnt--) {
            if (compare(mat, target)) {
                return true;
            }
            rotate(mat);
        }
        return false;
    }
    void rotate(vector<vector<int>> &mat) {
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(mat[i][j], mat[n-i-1][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    bool compare(vector<vector<int>> &mat, vector<vector<int>> &target) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != target[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};