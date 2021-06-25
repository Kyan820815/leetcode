//--- Q: 507. Perfect Number

//--- method 1: find i between 2 ~ sqrt(num)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
        int bound = sqrt(num);
        int sum = num-1;
        for (int i = 2; i <= bound; ++i) {
            if (num % i == 0) {
                if (i != num/i)
                    sum -= (i+num/i);
                else
                    sum -= i;
            }
        }
        return sum == 0;
    }
};