//--- Q: 1118. Number of Days in a Month

//--- method 1: find rule
class Solution {
public:
    int numberOfDays(int year, int month) {
        if (month == 2) {
            return (year%4 == 0 && (year%100 != 0 || year%400 == 0)) ? 29 : 28;
        } else {
            return 30 + (month < 8 ? month&1 : 1-month&1);
        }
    }
};