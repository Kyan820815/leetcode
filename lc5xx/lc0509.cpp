//--- Q: 509. Fibonacci Number

//--- method 1: dp iteration, O(1)
class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        else if (N == 1) return 1;
        int i_1 = 1, i_2 = 0, now;
        for (int i = 2; i <= N; ++i)
        {
        	now = i_1 + i_2;
        	i_2 = i_1;
        	i_1 = now;
        }
        return now;
    }
};