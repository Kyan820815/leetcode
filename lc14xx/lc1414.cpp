//--- Q: 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

//--- method 1: recursion, greedy
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k < 2) {
            return k;
        }
        int a = 1, b = 1;
        while (b <= k) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return 1 + findMinFibonacciNumbers(k-a);
    }
};

//--- method 2: iteration, greedy
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k < 2) {
            return k;
        }
        int a = 1, b = 1, res = 0;
        while (b <= k) {
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        while (k > 0) {
            if (a <= k) {
                k -= a;
                ++res;
            }
            int tmp = a;
            a = b-a;
            b = tmp;
        }
        return res;
    }
};