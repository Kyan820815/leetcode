//--- Q: 1133. Largest Unique Number

//--- method 1: O(1) space, O(n) time, bucket
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> cnt(1001, 0);
        for (int i = 0; i < A.size(); ++i) {
            ++cnt[A[i]];
        }
        for (int i = 1000; i >= 0; --i) {
            if (cnt[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};