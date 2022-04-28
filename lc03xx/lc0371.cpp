//--- Q: 0371. Sum of Two Integers

//--- method 1: bit manipulation
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int c = a & b;
            a ^= b;
            b = (c&0xffffffff) << 1;
        }
        return a;
    }
};