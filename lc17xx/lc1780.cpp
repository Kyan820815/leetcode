//--- Q: 1780. Check if Number is a Sum of Powers of Three

//--- method 1: greddy, always minus largest power of 3
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int times = 0, now = 1;
        while (now <= n) {
            ++times;
            now *= 3;
        }
        now /= 3;
        --times;
        while (times >= 0) {
            if (n >= now) {
                n -= now;
            }
            now /= 3;
            --times;
        }
        return !n;
    }
};

//--- method 2: number theory
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0 && n %3 != 2) {
            n = n%3 == 1 ? (n-1)/3 : n/3;
        }
        return n == 0;
    }
};