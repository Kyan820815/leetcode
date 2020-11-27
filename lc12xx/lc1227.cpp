//--- Q: 1227. Airplane Seat Assignment Probability

//--- method 1: math formula
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double last = 1;
        for (int i = 2; i <= n; ++i) {
            double cur = (double)1/i + (double)1/i*(i-2)*last;
            last = cur;
        }
        return last;
    }
};

//--- method 2: proof by math formula
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};