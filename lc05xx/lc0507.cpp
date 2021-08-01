//--- Q: 0507. Perfect Number

//--- method 1: find i between 2 ~ sqrt(num)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int limit = sqrt(num), sum = num-1;
        for (int i = 2; i <= limit; ++i) {
            if (num%i == 0) {
                sum -= i;
                if (num/i != i) {
                    sum -= num/i;
                }
            }
        }
        return num != 1 ? !sum : false;
    }
};