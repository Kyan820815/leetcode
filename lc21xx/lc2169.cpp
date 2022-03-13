//--- Q: 2169. Count Operations to Obtain Zero

//--- method 1: directly sub simulation
class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 < num2) {
            swap(num1, num2);
        }
        int res = 0;
        while (num1 && num2) {
            if (num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ++res;
        }
        return res;
    }
};

//--- method 2: modulo
class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 < num2) {
            swap(num1, num2);
        }
        int res = 0;
        while (num2) {
            res += num1/num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return res;
    }
};