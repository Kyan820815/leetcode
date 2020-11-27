//--- Q: 29. Divide Two Integers

//--- method 1: O(log(n)^2) time
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long long int a = abs(dividend), b = abs(divisor), res = 0, x = 0;
        while (a - b >= 0) {
            for (x = 0; (a - (b << x)) >= 0; ++x);
            --x;
            res += (1 << x);
            a -= b << x;

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
        long long int a = abs(dividend), b = abs(divisor), res = 0, x = 0;
        for (x = 31; x >= 0; --x) {
            if ((a >> x) - b >= 0) {
                res += 1 << x;
                a -= b << x;
            }
        }
        return dividend > 0 == divisor > 0 ? res : -res;
    }
};