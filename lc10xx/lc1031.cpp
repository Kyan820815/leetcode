//--- Q: 1031. Maximum Sum of Two Non-Overlapping Subarrays

//--- method 1: sliding window
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        for (int i = 1; i < n; ++i) {
            A[i] += A[i-1];
        }
        int res = A[L+M-1], lmax = A[L-1], mmax = A[M-1];
        for (int i = L+M; i < n; ++i) {
            lmax = max(lmax, A[i-M]-A[i-M-L]);
            mmax = max(mmax, A[i-L]-A[i-M-L]);
            res = max(res, max(lmax+A[i]-A[i-M], mmax+A[i]-A[i-L]));
        }
        return res;
    }
};

//--- method 2: find prefix sum and compare, two times
class Solution {
public:
    int n, res = 0;
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        n = A.size();
        vector<int> la(n, 0), ma(n, 0);
        setup(ma, M, A);
        find(ma, L, A);
        setup(la, L, A);
        find(la, M, A);
        return res;
    }
    void setup(vector<int> &arr, int len, vector<int> &A) {
        int sum = 0;
        for (int i = n-1; i >= n-len; --i) {
            sum += A[i];
        }
        arr[n-len] = sum;
        for (int i = n-len-1; i >= 0; --i) {
            sum += A[i];
            sum -= A[i+len];
            arr[i] = max(sum, arr[i+1]);
        }
    }
    void find(vector<int> &arr, int len, vector<int> &A) {
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += A[i];
        }
        res = max(res, sum+arr[len]);
        for (int i = len; i < n-1; ++i) {
            sum += A[i];
            sum -= A[i-len];
            res = max(res, sum+arr[i+1]);
        }
        
    }
};