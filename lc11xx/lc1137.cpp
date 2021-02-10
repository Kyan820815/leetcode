//--- Q: 1137. N-th Tribonacci Number

//--- method 1: tmp iteration
class Solution {
public:
    int tribonacci(int n) {
        if (!n) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        int r3 = 0, r2 = 1, r1 = 1;
        for (int i = 3; i <= n; ++i) {
            int tmp = r1+r2+r3;
            r3 = r2;
            r2 = r1;
            r1 = tmp;
        }
        return r1;
    }
};

//--- method 2: loop around index
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp = {0,1,1};
        for (int i = 3; i <= n; ++i) {
            int sum = dp[0]+dp[1]+dp[2];
            dp[i%3] = sum;
        }
        return dp[n%3];
    }
};