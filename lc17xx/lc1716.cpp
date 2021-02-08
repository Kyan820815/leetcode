//--- Q: 1716. Calculate Money in Leetcode Bank

//--- method 1: O(1) math
class Solution {
public:
    int totalMoney(int n) {
        --n;
        int row = n/7, col = n%7;
        return  28*row+(row-1)*7*row/2 + (1+row+col+1+row)*(col+1)/2;
    }
};

//--- method 2: O(n) loop
class Solution {
public:
    int totalMoney(int n) {
        int s = 0, res = 0, now;
        for (int i = 0; i < n; ++i) {
            if (i%7 == 0) {
                ++s;
                now = s;
            }
            res += now++;
        }
        return res;
    }
};