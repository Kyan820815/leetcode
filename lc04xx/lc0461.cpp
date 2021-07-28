//--- Q: 0461. Hamming Distance

//--- method 1: xor with remove the rightest one method
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y, res = 0;
        while (n) {
            ++res;
            n &= (n-1);
        }
        return res;
    }
};