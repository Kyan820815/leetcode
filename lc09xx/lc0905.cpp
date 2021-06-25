//--- Q: 905. Sort Array By Parity

//--- method 1: odd even change, partition of quick select
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int start = -1;
        for (int i = 0; i < A.size(); ++i)
        {
        	if ((A[i] & 1) == 0)
        		swap(A[++start], A[i]);
        }
        return A;
    }
};