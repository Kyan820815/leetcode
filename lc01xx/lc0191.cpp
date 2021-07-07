//--- Q: 0191. Number of 1 Bits

//--- method 1: bit operation
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += (n&1);
            n >>= 1;
        }
        return res;
    }
};

//--- method 2: bit operation counting 1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= (n-1);
            ++res;
        }
        return res;
    }
};