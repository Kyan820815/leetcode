//--- Q: 0326. Power of Three

//--- method 1: iteration
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n%3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

//--- method 2: bit manipulation
class Solution {
public:
    bool isPowerOfThree(int n) {
        int max_power_of_3 = pow(3, int(log(INT_MAX)/log(3)));
        return n > 0 && max_power_of_3 % n == 0;
    }
};