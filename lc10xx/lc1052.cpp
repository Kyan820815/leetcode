//--- Q: 1052. Grumpy Bookstore Owner

//--- method 1: clean code
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(), gval = 0, ngval = 0, mgval = 0;
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                ngval += customers[i];
            } else {
                gval += customers[i];
            }
            if (i >= minutes && grumpy[i-minutes]) {
                gval -= customers[i-minutes];
            }
            mgval = max(mgval, gval);
        }
        return ngval + mgval;
    }
};