//--- Q: 276. Paint Fence

//--- method 1:  O(1) space, dp
class Solution {
public:
    int numWays(int n, int k) {
        if (!n) {
            return 0;
        } else if (n == 1) {
            return k;
        } else if (n == 2) {
            return k * k;
        }
        int n_2 = k, n_1 = k*k;
        for (int i = 3; i <= n; ++i) {
            n_1 += n_2;
            n_2 = n_1 - n_2;
            n_1 *= (k-1);
        }
        return n_1;
    }
};