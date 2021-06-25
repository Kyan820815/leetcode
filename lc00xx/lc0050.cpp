//--- Q: 050. Pow(x, n)

//--- method 1: recursive solution
class Solution {
public:
    double myPow(double x, int n) {
        double addone = 1;
        if (n < 0) {
            x = 1/x;
            if (n == INT_MIN) {
                n = INT_MAX;
                addone = 1/x;
            } else {
                n *= -1;
            }
        }
        return dfs(x, n) * addone;
    }
    double dfs(double x, int n) {
        if (!n) {
            return 1;
        } else if (n == 1) {
            return x;
        } else {
            double rtn = dfs(x, n/2);
            return rtn * rtn * ((n%2==1) ? x : 1);
        }
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