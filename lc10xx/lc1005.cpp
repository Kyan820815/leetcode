//--- Q: 1005. Maximize Sum Of Array After K Negations

//--- method 1: O(n) quick select
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int sum = 0, minv = INT_MAX;
        divide(A, 0, A.size()-1, K-1);
        for (int i = 0; i < A.size(); ++i) {
            if (K && A[i] < 0) {
                A[i] *= -1;
                --K;
            }
            sum += A[i];
            minv = min(minv, A[i]);
        }
        if (K & 1)
            sum -= 2*minv;
        return sum;
    }
    int partition(vector<int> &A, int start, int end) {
        int pivot = start + rand()%(end-start+1), mid = start-1;
        swap(A[pivot], A[end]);
        for (int i = start; i < end; ++i) {
            if (A[i] < A[end])
                swap(A[++mid], A[i]);
        }
        swap(A[++mid], A[end]);
        return mid;
    }
    void divide(vector<int> &A, int start, int end, int K) {
        if (start < end) {
            int mid = partition(A, start, end);
            if (mid < K)
                divide(A, mid+1, end, K);
            else if (mid > K)
                divide(A, start, mid-1, K);
            else
                return;
        }
    }
};