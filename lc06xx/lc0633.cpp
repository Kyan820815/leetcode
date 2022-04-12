//--- Q: 0633. Sum of Square Numbers

//--- method 1: two pointers
class Solution {
public:
    using ll = long long;
    bool judgeSquareSum(int c) {
        ll left = 0, right = sqrt(c);
        while (left <= right) {
            if (left*left + right*right < c) {
                ++left;
            } else if (left*left + right*right > c) {
                --right;
            } else {
                return true;
            }
        }
        return false;
    }
};