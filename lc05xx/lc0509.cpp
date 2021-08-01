//--- Q: 0509. Fibonacci Number

//--- method 1: dp iteration, O(1)
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        auto i_1 = 1, i_2 = 0;
        for (int i = 2; i <= n; ++i) {
            auto tmp = i_1 + i_2;
            i_2 = i_1;
            i_1 = tmp;
        }
        return i_1;
    }
};