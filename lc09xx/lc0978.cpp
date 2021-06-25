//--- Q: 978. Longest Turbulent Subarray

//--- method 1: O(n) time, O(1) space
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res = 0, cnt = 1, sign = -1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1] && (!sign || sign == -1)) {
                sign = 1;
                ++cnt;
            } else if (A[i] < A[i-1] && (sign || sign == -1)) {
                sign = 0;
                ++cnt;
            } else {
                res = max(res, cnt);
                if (A[i] > A[i-1] || A[i] < A[i-1])
                    cnt = 2;
                else {
                    cnt = 1;
                    sign = -1;
                }    
            }
        }
        res = max(res, cnt);
        return res;
    }
};