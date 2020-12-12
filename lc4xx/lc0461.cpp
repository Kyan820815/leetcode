//--- Q: 461. Hamming Distance

//--- method 1: xor with remove the rightest one method
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int n = x ^ y;
        while (n) {
            ++res;
            n &= (n-1);
        }
        return res;
    }
};