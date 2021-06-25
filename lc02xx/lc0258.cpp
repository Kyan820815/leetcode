//--- Q: 258. Add Digits

//--- method 1: find law
class Solution {
public:
    int addDigits(int num) {
        return num > 9 ? num%9 : num;
    }
};