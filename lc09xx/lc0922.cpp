//--- Q: 922. Sort Array By Parity II

//--- method 1: O(1) space, swap
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 0, j = 1; i < A.size() && j < A.size(); i += 2, j += 2) {
            while (i < A.size() && !(A[i]&1)) {
                i += 2;
            }
            while (j < A.size() && (A[j]&1)) {
                j += 2;
            }
            if (i < A.size()) {
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};

//--- method 2: double pointer
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        vector<int> res(A.size());
        for (int k = 0; k < A.size(); ++ k) {
            if (A[k]&1) {
                res[j] = A[k];
                j += 2;
            } else {
                res[i] = A[k];
                i += 2;
            }
        }
        return res;
    }
};