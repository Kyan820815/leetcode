//--- Q: 1072. Flip Columns For Maximum Number of Equal Rows

//--- method 1: find maximum patterns based on rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> map;
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        for (int i = 0; i < row; ++i) {
            string tmp = "";
            for (int j = 0; j < col; ++j) {
                tmp += (matrix[i][j] == matrix[i][0] ? '1' : '0');
            }
            res = max(res, ++map[tmp]);
        }
        return res;
    }
};