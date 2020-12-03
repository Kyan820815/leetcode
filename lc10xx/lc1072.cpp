//--- Q: 1072. Flip Columns For Maximum Number of Equal Rows

//--- method 1: find maximum patterns based on rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), maxv = 0;
        unordered_map<string, int> map;
        for (int i = 0; i < row; ++i) {
            string str = "";
            int change = (matrix[i][0] == 1);
            for (int j = 0; j < col; ++j) {
                str.push_back(matrix[i][j]^change + '0');
            }
            maxv = max(maxv, ++map[str]);
        }
        return maxv;
    }
};
