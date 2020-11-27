//--- Q: 989. Add to Array-Form of Integer

//--- method 1: linear processing
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size()-1;
        while (i >= 0 && K) {
            int now = K + A[i];
            A[i--] = now % 10;
            K = now / 10;
        }
        while (K) {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};