//--- Q: 1007. Minimum Domino Rotations For Equal Row

//--- method 1: one pass, find cnt for the first domino
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int top = A[0], down = B[0], tcnt1 = 0, dcnt1 = 0, tcnt2 = 0, dcnt2 = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != top && B[i] != top) {
                top = 0;
            }
            if (A[i] != down && B[i] != down) {
                down = 0;
            }
            if (!top && !down) {
                return -1;
            }
            tcnt1 += top == A[i];
            dcnt1 += top == B[i];
            tcnt2 += down == A[i];
            dcnt2 += down == B[i];
        }
        return min(A.size() - max(tcnt1, dcnt1), A.size() - max(tcnt2, dcnt2));
    }
};