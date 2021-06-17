//--- Q: 0007. Reverse Integer

//--- method 1: index by index checking, better
class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        while (x) {
            int rem = x%10;
            if (sum > INT_MAX/10 || sum == INT_MAX/10 && rem > 7) {
                return 0;
            }
            if (sum < INT_MIN/10 || sum == INT_MIN/10 && rem < -8) {
                return 0;
            }
            sum = sum*10 + rem;
            x /= 10;
        }
        return sum;
    }
};