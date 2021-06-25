//--- Q: 941. Valid Mountain Array

//--- method 1: one way check
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0;
        if (A.size() < 3) {
            return false;
        }
        while (i < A.size()-1 && A[i] < A[i+1]) {
            ++i;
        }
        if (!i || i == A.size() - 1) {
            return false;
        }
        while (i < A.size()-1 && A[i] > A[i+1]) {
            ++i;
        }
        return i == A.size()-1;
    }
};