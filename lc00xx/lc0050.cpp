//--- Q: 0050. Pow(x, n)

//--- method 1: iterative solution
class Solution {
public:
    double myPow(double x, int n) {
        double add = 1, res = 1;
        if (n < 0) {
            x = 1/x;
            if (n == INT_MIN) {
                ++n;
                add = x;
            }
            n = -n;
        }
        while (n) {
            if (n&1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res*add;      
    }
};

//--- method 2: recursive solution
class Solution {
public:
    double myPow(double x, int n) {
        double add = 1;
        if (n < 0) {
            x = 1/x;
            if (n == INT_MIN) {
                ++n;
                add = x;
            }
            n = -n;
        }
        double res = dfs(x, n);
        return res*add;      
    }
    double dfs(double x, int n) {
        if (!n) {
            return 1;
        } else if (n == 1) {
            return x;
        } else {
            double rtn = dfs(x, n/2);
            return rtn*rtn * (n&1 ? x : 1);
        }
    }
};