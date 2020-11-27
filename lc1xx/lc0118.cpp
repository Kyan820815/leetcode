//--- Q: Pascal's Triangle

//--- method 1: dp iteration
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i)
        {
        	vector<int> res_vec;
        	res_vec.push_back(1);
        	for (int j = 1; j < i; ++j)
        		res_vec.push_back(res[i-1][j]+res[i-1][j-1]);
        	if (i > 0) res_vec.push_back(1);
        	res.push_back(res_vec);
        }
        return res;
    }
};