//--- Q: 1072. Flip Columns For Maximum Number of Equal Rows

//--- method 1: find maximum patterns based on rows
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> map;
        int row = matrix.size(), col = matrix[0].size();
        int maxv = 0;
        for (int i = 0; i < row; ++i) {
            string res = "";
            if (matrix[i][0] == 0) {
                for (int j = 0; j < col; ++j)
                    res += matrix[i][j] + '0';
            } else {
                for (int j = 0; j < col; ++j)
                    res += (matrix[i][j]^1) + '0';
            }
            maxv = max(maxv, ++map[res]);
        }
        return maxv;
    }
};
