//--- Q: 0201. Bitwise AND of Numbers Range

//--- method 1: naive bit operation
class Solution {
public:
    using ll = long long;
    int rangeBitwiseAnd(int left, int right) {
        int res = 0, cur = 0, bit = 1;
        for (int i = 0; i < 31; ++i) {
            if (bit & left) {
                cur += bit;
                if (left-cur+(((ll)bit) << 1) > right) {
                    res += bit;
                }
            }
            bit <<= 1;
        }
        return res;
    }
};

//--- method 2: find shared bits
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right &= (right-1);
        }
        return right;
    }
};