//--- Q: 050. Pow(x, n)

//--- method 1: recursive solution
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double overflow = 1;
        if (n < 0) {
            if (n == INT_MIN) {
                n++;
                overflow = 1/x;
            }
            n *= -1;
            x = 1/x;
        }
        return dfs(x, n) * overflow;
    }
    double dfs(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double now = dfs(x, n/2);
        return (n&1) == 1 ? x*now*now : now*now;
    }
};

//--- method 2: iterative solution
class Solution {
public:
    double myPow(double x, int n) {
    	double out = 1;
    	double p = x;
    	int m = (n < 0) ? abs(n+1) : n;
    	for (int i = m; i != 0; i/=2)
    	{
    		if (i%2 == 1) out *= p;
    		p *= p;
    	}
    	return (n < 0) ? 1/out/x : out;
    }
};