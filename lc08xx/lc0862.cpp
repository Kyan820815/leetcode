//--- Q: 862. Shortest Subarray with Sum at Least K

//--- method 1: sliding window
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int left = 0, right = 0, n = A.size(), res = INT_MAX;
        deque<int> que;
        while (right < n) {
            if (right) {
                A[right] += A[right-1];
            }
            if (A[right] >= K) {
                res = min(res, right+1);
            }
            while (que.size() && A[right] - A[que.front()] >= K) {
                res = min(res, right-que.front());
                que.pop_front();
            }
            while (que.size() && A[right] - A[que.back()] <= 0) {
                que.pop_back();
            }
            que.push_back(right++);
        }
        return res == INT_MAX ? -1 :res;
    }
};