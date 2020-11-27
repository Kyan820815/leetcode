//--- Q: 1118. Number of Days in a Month

//--- method 1: find rule
class Solution {
public:
    int numberOfDays(int Y, int M) {
        if (M == 2)
            return (Y % 100 == 0 && Y % 400 != 0 || Y % 4 != 0) ? 28 : 29;
        return 30 + ((M >= 8) ? 1 - M&1 : M&1);
    }
};