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
        int first = 0, second = 1, thrid = 1;
        for (int i = 3; i <= n; ++i) {
            int tmp = first+second+thrid;
            first = second;
            second = thrid;
            thrid = tmp;
        }
        return thrid;
    }
};

//--- method 2: loop around index
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp = {0,1,1};
        for (int i = 3; i <= n; ++i) {
            int tmp = dp[0]+dp[1]+dp[2];
            dp[i%3] = tmp;
        }
        return dp[n%3];
    }
};