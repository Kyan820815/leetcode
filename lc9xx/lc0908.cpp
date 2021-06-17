//--- Q: 908. Smallest Range I

//--- method 1: find max and min
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxv = INT_MIN, minv = INT_MAX;
        for (int i = 0; i < A.size(); ++i) {
            maxv = max(maxv, A[i]);
            minv = min(minv, A[i]);
        }
        return maxv-minv <= 2*K ? 0 : maxv-minv-2*K;
    }
};
