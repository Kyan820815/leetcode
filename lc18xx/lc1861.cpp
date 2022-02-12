//--- Q: 1861. Rotating the Box

//--- method 1: two pointers
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(), col = box[0].size();
        vector<vector<char>> res(col, vector<char>(row, '.'));
        for (int i = 0; i < row; ++i) {
            for (int j = col-1, k = col-1; j >= 0; --j) {
                if (box[i][j] != '.') {
                    k = box[i][j] == '*' ? j : k;
                    res[k--][row-i-1] = box[i][j];
                }
            }
        }
        return res;
    }
};