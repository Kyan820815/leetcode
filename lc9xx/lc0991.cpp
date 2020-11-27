//--- Q: 991. Broken Calculator

//--- method 1: find pattern
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (X < Y) {
            if ((Y&1) == 0) {
                Y >>= 1;
            } else {
                Y += 1;
            }
            ++res;
        }
        return res + X - Y;
    }
};