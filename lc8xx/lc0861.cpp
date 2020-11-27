//--- Q: 861. Score After Flipping Matrix

//--- method 1: greedy approach
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        int res = (1 << col-1) * row;
        for (int j = 1; j < col; ++j)
        {
        	int cnt = 0;
        	for (int i = 0; i < row; ++i)
        		cnt += (A[i][j] == A[i][0]);
        	res += max(cnt, row-cnt)*(1 << col-j-1);
        }
        return res;
    }
};