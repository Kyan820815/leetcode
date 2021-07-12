//--- Q: 0276. Paint Fence

//--- method 1:  O(1) space, dp
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) {
            return k;
        } else if (n == 2) {
            return k*k;
        };
        int last2 = k, last1 = k*k;
        for (int i = 3; i <= n; ++i) {
            auto tmp = (last1+last2) * (k-1);
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
};