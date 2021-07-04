//--- Q: 0120. Triangle

//--- method 1: O(1) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        for (int i = row-1; i >= 1; --i) {
            for (int j = 0; j < i; ++j) {
                triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
            }
        }
        return triangle[0][0];
    }
};