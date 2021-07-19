//--- Q: 0342. Power of Four

//--- method 1: iteration
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        while (n%4 == 0) {
            n /= 4;
        }
        return n == 1;
    }
};

//--- method 2: bit manipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n&(n-1)) == 0 && (n&0x55555555);
    }
};