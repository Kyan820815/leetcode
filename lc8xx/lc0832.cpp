//--- Q: 832. Flipping an Image

//--- method 1: 
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i)
        	reverse(A[i].begin(), A[i].end());
        for (int i = 0; i < A.size(); ++i)
        	for (int j = 0; j < A[i].size(); ++j)
				A[i][j] ^= 1;
		return A;        		
    }
};

//--- method 2: copy then rewrite
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    	vector<vector<int>> B(A.size());
        for (int i = 0; i < A.size(); ++i)
        	for (int j = A[i].size()-1; j >= 0; --j)
				B[i].push_back(A[i][j]^1);
		return B;        		
    }
};