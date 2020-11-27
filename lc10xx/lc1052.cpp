//--- Q: 1052. Grumpy Bookstore Owner

//--- method 1: clean code
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int grum = 0, res = 0, not_grum = 0;;
        for (int i = 0; i < grumpy.size(); ++i) {
            if (!grumpy[i]) {
                not_grum += customers[i];
            } else {
                grum += customers[i];
            }
            if (i >= X && grumpy[i-X]) {
                grum -= customers[i-X];
            }
            res = max(res, grum);
        }
        return res + not_grum;
    }
};

//--- method 2: my version
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0, val = 0;
        for (int i = 0; i < X; ++i)
        	val += customers[i];
        for (int i = X; i < customers.size(); ++i)
        {
        	if (!grumpy[i])
        		val += customers[i];
        }
        res = val;
        for (int i = X; i < customers.size(); ++i)        
		{
			if (grumpy[i])
				val += customers[i];
			if (grumpy[i-X])
				val -= customers[i-X];
			res = max(res, val);
		}
		return res;
    }
};