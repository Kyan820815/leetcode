//--- Q: 1492. The kth Factor of n

//--- method 1: sqrt n processing
class Solution {
public:
    int kthFactor(int n, int k) {
        int d;
        for (d = 1; d*d <= n; ++d) {
            if (n%d == 0 && --k == 0) {
                return d;
            }
        }
        for (d = d-1; d >= 1; --d) {
            if (d*d == n) {
                continue;
            }
            if (n%d == 0 && --k == 0) {
                return n/d;
            }
        }
        return -1;
    }
};