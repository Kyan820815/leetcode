//--- Q: 1329. Sort the Matrix Diagonally

//--- method 1: priority queue
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                map[i-j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                mat[i][j] = map[i-j].top();
                map[i-j].pop();
            }
        }
        return mat;
    }
};

//--- method 2: my version
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int start = row-1;
        while (start >= 0) {
            int r = start, c = 0;
            deque<int> tmp;
            while (r < row && c < col) {
                tmp.push_back(mat[r++][c++]);
            }
            sort(tmp.begin(), tmp.end());
            r = start, c = 0;
            while (r < row && c < col) {
                mat[r++][c++] = tmp.front();
                tmp.pop_front();
            }
            --start;
        }
        start = 1;
        while (start < col) {
            int r = 0, c = start;
            deque<int> tmp;
            while (r < row && c < col) {
                tmp.push_back(mat[r++][c++]);
            }
            sort(tmp.begin(), tmp.end());
            r = 0, c = start;
            while (r < row && c < col) {
                mat[r++][c++] = tmp.front();
                tmp.pop_front();
            }
            ++start;
        }
        return mat;
    }
};
