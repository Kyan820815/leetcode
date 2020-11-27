//--- Q: 191. Number of 1 Bits

//--- method 1: bit operation
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            res += (n & 1);
        	n >>= 1;
        }
        return res;
    }
};