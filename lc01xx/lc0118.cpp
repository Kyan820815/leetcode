//--- Q: 0118. Pascal's Triangle
//--- last written: 2023/07/13

//--- method 1: dp iteration
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {{1}};
        for (int i = 1; i < numRows; ++i) {
            vector<int> tmp = {1};
            for (int j = 1; j < i; ++j) {
                tmp.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};