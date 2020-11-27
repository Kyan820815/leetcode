//--- Q: 1099. Two Sum Less Than K

//--- method 1: two pointers
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int left = 0, right = A.size()-1;
        int diff = INT_MAX;
        sort(A.begin(), A.end());
        while (left < right) {
            int sum = A[left] + A[right];
            if (sum < K) {
                diff = min(diff, K-sum);
                ++left;
            } else
                --right;
        }
        return diff == INT_MAX ? -1 : K-diff;
    }
};