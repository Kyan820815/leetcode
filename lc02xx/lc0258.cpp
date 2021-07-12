//--- Q: 0258. Add Digits

//--- method 1: naive method
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmp = 0;
            while (num) {
                tmp += num%10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};

//--- method 2: find law
class Solution {
public:
    int addDigits(int num) {
        return num < 10 ? num : (num%9 == 0 ? 9 : num%9);
    }
};