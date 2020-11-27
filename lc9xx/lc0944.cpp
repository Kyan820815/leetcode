//--- Q: Delete Columns to Make Sorted

//--- method 1: brute force
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A[0].size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < A.size(); ++j) {
                if (A[j][i] < A[j-1][i]) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};