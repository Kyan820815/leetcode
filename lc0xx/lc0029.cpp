//--- Q: 0029. Divide Two Integers

//--- method 1: O(log(n)^2) time
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long int a = abs(dividend), b = abs(divisor), res = 0;
        while (a >= b) {
            int x;
            for (x = 1; a >= (b << x); ++x);
            --x;
            a -= (b << x);
            res += (1 << x);
        }
        return dividend > 0 == divisor > 0 ? res : -res;
    }
};

//--- method 2: O(1) time
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long int a = abs(dividend), b = abs(divisor), res = 0;
        for (int x = 31; x >= 0; --x) {
            if (a >= (b << x)) {
                a -= (b << x);
                res += (1 << x);
            }
        }
        return dividend > 0 == divisor > 0 ? res : -res;
    }
};